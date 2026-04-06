**Rol:** Eres un Ingeniero de Software Senior especializado en Interoperabilidad de Sistemas, WebAssembly (Wasm) y optimización de Runtimes. Tu misión es implementar una prueba de concepto (PoC) que conecte el framework Flutter con lógica de negocio escrita en C# compilada a Wasm, utilizando JavaScript como puente de comunicación.

**Directrices de Ejecución:**
*   **Minimalismo Estricto:** Los archivos generados deben ser lo más pequeños posible. Debes priorizar configuraciones de **NativeAOT** y recorte de código (trimming) en C# para evitar el peso del framework .NET completo.
*   **Transparencia de Datos:** La comunicación entre runtimes (Dart <-> JS <-> C#) debe ser explícita. Utiliza tipos primitivos (`int`) para esta PoC para evitar la complejidad de la serialización, facilitando el aprendizaje.
*   **Ciclo de Vida de Carga:** Debes garantizar que el módulo Wasm esté instanciado y listo antes de que Flutter intente realizar cualquier llamada. Implementa señales claras de "Listo" en el puente JS.
*   **Restricciones AOT:** En el lado de C#, evita cualquier uso de reflexión o librerías dinámicas que no sean compatibles con la compilación NativeAOT para WebAssembly.
*   **Estándares Modernos:** Utiliza `package:web` y `dart:js_interop` en Flutter, siguiendo las recomendaciones actuales de Google para aplicaciones web, reemplazando las bibliotecas legadas.

---

### 2. Resumen General de la Implementación (Hito 1)

**Objetivo:** Establecer una tubería de comunicación funcional entre Flutter Web y un binario Wasm de C# para realizar una operación aritmética simple (suma), sirviendo como base educativa para arquitecturas más complejas.

**Alcance Técnico del Hito 1:**
1.  **Módulo de Cómputo (C#):** Creación de una biblioteca de clases optimizada para NativeAOT que exporte la función `Sumar`.
2.  **Infraestructura de Puente (JS):** Creación de un cargador asíncrono para el runtime de .NET y la exposición de la API al objeto global `window`.
3.  **Capa de Interfaz (Flutter):** Implementación de la UI y el mapeo de interoperabilidad mediante tipos de extensión de Dart.
4.  **Orquestación de Despliegue:** Configuración de la estructura de carpetas para que el servidor web entregue los tipos MIME correctos.

---

### 3. Fase 1: Configuración del Entorno y Proyecto C# (NativeAOT)

**Objetivo:** Configurar el proyecto de C# para generar el archivo `.wasm` más pequeño y eficiente posible.

**Actividades:**
1.  **Inicialización del Proyecto:** Crear un proyecto de tipo `console` o `classlib` orientado a .NET 8/9.
2.  **Configuración del SDK:** Instalar la carga de trabajo (workload) de .NET para WebAssembly (`wasm-tools`).
3.  **Definición del Archivo de Proyecto (.csproj):**
    *   Habilitar `PublishTrimmed` para eliminar código muerto.
    *   Configurar `RuntimeIdentifier` como `browser-wasm`.
    *   Habilitar el soporte para `WasmEnableThreads` (falso para simplicidad) y `WasmEnableSIMD`.
4.  **Lógica de Cómputo:**
    *   Implementar una clase estática con el método `Sumar(int a, int b)`.
    *   Decorar el método con el atributo `[JSExport]` para que sea visible desde el motor de JavaScript.
    *   Configurar el punto de entrada para que el runtime de .NET permanezca activo sin ejecutar lógica de consola.

**Resultado Esperado de esta Fase:** Un proyecto C# listo para ser compilado en un archivo `logic.wasm` de tamaño mínimo.

---

### Fase 2: El Puente JavaScript (Glue Code)

**Objetivo:** Crear el orquestador que inicializa el runtime de .NET dentro del navegador y expone la lógica de C# hacia el entorno global de la aplicación web.

**Actividades:**
1.  **Gestión de Módulos ES6:**
    *   Configurar el script para que funcione como un módulo de JavaScript para permitir el uso de `import` desde el archivo `dotnet.js` generado por la compilación de C#.
2.  **Configuración del Runtime de .NET:**
    *   Definir el objeto de configuración que indica dónde encontrar los binarios `.wasm` y los recursos del framework.
    *   Utilizar el método `create()` del objeto `dotnet` para instanciar el runtime de forma asíncrona.
3.  **Mapeo de Funciones Exportadas:**
    *   Extraer las funciones marcadas con `[JSExport]` desde el namespace del ensamblado de C#.
    *   Crear un objeto global en el navegador (`window.wasmBridge`) que actúe como un proxy. Esto evita que Dart tenga que conocer la estructura interna del runtime de .NET.
4.  **Implementación del Contrato de Suma:**
    *   Crear una función de envoltura (wrapper) en JS que reciba los parámetros desde Dart, los asegure como tipos numéricos y llame a la función correspondiente de C#.
5.  **Señalización de Estado (Readiness):**
    *   Implementar un mecanismo de notificación (puede ser una `Promise` global o una bandera booleana en `window`) que indique a Flutter que el motor de C# ha terminado de cargarse y está listo para recibir peticiones.

**Resultado Esperado de esta Fase:** Un archivo `loader.js` que oculte la complejidad del runtime de .NET y ofrezca una API limpia y estática a la que Flutter pueda conectarse.

---

### Fase 3: Capa de Interoperabilidad en Dart (`dart:js_interop`)

**Objetivo:** Definir el contrato en Flutter para que el compilador de Dart reconozca y pueda llamar a las funciones expuestas en el Puente JavaScript.

**Actividades:**
1.  **Definición de Extension Types:**
    *   Utilizar el nuevo estándar de Dart 3.x para crear un `extension type` sobre `JSObject`.
    *   Definir la estructura del objeto global `wasmBridge` que creamos en la Fase 2.
2.  **Mapeo de Métodos Externos:**
    *   Declarar el método `external` para la suma, asegurando que los tipos de datos coincidan con los de JS (usando `JSNumber`).
    *   Establecer la vinculación con el objeto `window` mediante el uso de `@JS()`.
3.  **Abstracción de Servicio:**
    *   Crear una clase `WasmCalculatorService` en Dart que encapsule la lógica de interoperabilidad.
    *   Implementar un método `add(int a, int b)` que realice la conversión de tipos de Dart a JS y viceversa de forma transparente para el resto de la aplicación.
4.  **Manejo de Promesas (Opcional):**
    *   Si la inicialización en JS es asíncrona, implementar un método en Dart que espere a que la `Promise` de JS se resuelva antes de permitir llamadas a la lógica de cálculo.

**Resultado Esperado de esta Fase:** Un archivo `web_interop.dart` que permita llamar a la lógica de C# como si fuera una función nativa de Dart, con seguridad de tipos.

---

### Fase 4: Interfaz de Usuario y Gestión de Estado (Flutter)

**Objetivo:** Construir una interfaz minimalista y reactiva que interactúe con el servicio Wasm, gestionando los estados de carga y validación.

**Actividades:**
1.  **Diseño de la Pantalla Principal:**
    *   Implementar un `Scaffold` con dos campos de texto (`TextField`) restringidos a entrada numérica (`FilteringTextInputFormatter.digitsOnly`).
    *   Añadir un botón de acción "Calcular Suma".
    *   Crear un área de visualización para el resultado.
2.  **Gestión de Estado Simple:**
    *   Utilizar un `ValueNotifier<bool>` para rastrear si el módulo Wasm está cargado y listo.
    *   Utilizar un `ValueNotifier<int?>` para almacenar y mostrar el resultado de la operación.
3.  **Lógica de Vinculación (Binding):**
    *   Implementar una función de manejo de eventos para el botón que extraiga los valores de los `TextEditingControllers`.
    *   Llamar al método de suma del `WasmCalculatorService` definido en la Fase 3.
4.  **Feedback de Usuario:**
    *   Deshabilitar el botón de cálculo y mostrar un indicador de progreso (`CircularProgressIndicator`) mientras el estado de carga del Wasm sea falso.
    *   Implementar una validación básica para asegurar que los campos no estén vacíos antes de invocar al puente.

**Resultado Esperado de esta Fase:** Una aplicación Flutter funcional que reacciona al estado del módulo WebAssembly y permite la interacción del usuario.

---

### Fase 5: Compilación, Ensamblaje y Despliegue

**Objetivo:** Integrar todos los componentes (C#, JS, Flutter) en un paquete de despliegue coherente y configurar el entorno de ejecución.

**Actividades:**
1.  **Script de Compilación de C#:**
    *   Ejecutar `dotnet publish` con los flags de optimización para NativeAOT.
    *   Identificar y mover los archivos resultantes (`logic.wasm` y el archivo de soporte `dotnet.js`) a la carpeta `web/` del proyecto Flutter.
2.  **Configuración del Punto de Entrada Web:**
    *   Modificar `web/index.html` para incluir el script `loader.js` (Fase 2) como un módulo (`type="module"`).
    *   Asegurar que la carga del script de Flutter ocurra en el orden correcto respecto a la inicialización del motor de .NET.
3.  **Compilación de Flutter Web:**
    *   Ejecutar `flutter build web --release`.
    *   Verificar que los activos de C# se incluyan correctamente en el bundle final de `build/web/`.
4.  **Configuración del Servidor de Pruebas:**
    *   Preparar un servidor local (ej. Python `http.server`) para servir la aplicación.
    *   **Crucial:** Configurar o verificar que el servidor responda con el encabezado `Content-Type: application/wasm` para los archivos `.wasm`.
5.  **Validación de Fin a Fin:**
    *   Cargar la aplicación en un navegador moderno.
    *   Inspeccionar la consola de desarrollador para confirmar la carga exitosa de los módulos y la ejecución de la suma.

**Resultado Esperado de esta Fase:** Una aplicación web lista para ser desplegada en cualquier servidor estático, con todos los runtimes (Dart, JS, .NET) operando en armonía.
