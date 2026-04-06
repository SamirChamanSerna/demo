# Referencia Técnica: Arquitectura de Interoperabilidad (Wasm)

Este documento explica cómo están estructurados los componentes técnicos para conectar Flutter Web con C# NativeAOT.

---

## 1. Módulo de Cómputo (C#)
*   **Proyecto:** `wasm_logic/WasmLogic.csproj`
*   **Ensamblado:** `WasmLogic.wasm` (generado en la carpeta `_framework`).
*   **Puntos Críticos:**
    *   **NativeAOT:** El SDK `WebAssembly` de .NET 8 se usa para generar un binario Wasm que no requiere un runtime completo descargado.
    *   **Exportación:** El atributo `[JSExport]` en `Logic.cs` expone los métodos de C# hacia el objeto de exportación de JavaScript de .NET.
    *   **Clase Parcial:** La clase que contiene `[JSExport]` debe ser `partial` para permitir al compilador inyectar el código de interoperabilidad.

## 2. El Puente (JavaScript)
*   **Archivo:** `web/loader.js` (basado en `web_bridge/loader.js`).
*   **Importación:** Usa el sistema de módulos de JS (`import { dotnet } from './dotnet.js'`).
*   **Inicialización:**
    *   Llama a `dotnet.create()` para arrancar el runtime de .NET.
    *   Extrae las funciones exportadas mediante `getAssemblyExports(config.mainAssemblyName)`.
    *   Crea un objeto proxy global `window.wasmBridge` que actúa como la API final para Dart.
*   **Sincronización:** Emite un evento personalizado `wasm-ready` para notificar al entorno web.

## 3. Capa de Interfaz (Dart/Flutter)
*   **Archivo:** `lib/wasm_interop.dart`.
*   **SDK Mínimo:** Requiere Dart >= 3.3.0 para usar **Extension Types**.
*   **Interoperabilidad:**
    *   `@JS('wasmBridge')`: Permite a Dart acceder a la propiedad global de JavaScript.
    *   `extension type WasmBridge(JSObject _)`: Crea un contrato estático sobre un objeto JS sin el peso de una clase Dart tradicional.
    *   `JSAny?`: Se usa como tipo raíz compatible con el nuevo sistema de interoperabilidad (`dart:js_interop`).
*   **Servicio:** `WasmCalculatorService` encapsula las conversiones `toJS` y `toDartInt`.

## 4. Estructura de Binarios (Compilación)
El compilador de C# genera un ecosistema de archivos en la carpeta `_framework` que deben residir en la raíz de la web de Flutter:
*   `dotnet.js`: El cargador principal.
*   `WasmLogic.wasm`: Tu lógica de C#.
*   `dotnet.native.wasm`: El motor de ejecución nativo.
*   `System.Private.CoreLib.wasm`: Tipos básicos de .NET (int, string, etc.).
*   `*.dat`: Datos de internacionalización (ICU) necesarios para el soporte de cadenas y fechas.

## 5. Ciclo de Vida de Ejecución
1.  **Navegador** descarga `index.html`.
2.  `index.html` carga `loader.js` como un módulo.
3.  **Módulo JS** descarga y arranca `dotnet.js`.
4.  **Flutter** se inicia en paralelo al motor .NET.
5.  **Flutter UI** verifica `wasmBridge.ready` mediante un `Timer`.
6.  Cuando es `true`, el botón de la UI se habilita para realizar llamadas.
