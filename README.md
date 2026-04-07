# PoC: Flutter + C# NativeAOT (Multiplataforma)

Esta prueba de concepto demuestra cómo compartir lógica de negocio escrita en C# entre Flutter Web (WebAssembly), Windows (DLL) y Android (Librería Nativa .so).

---

## 1. Prerrequisitos Comunes

1.  **.NET 8 SDK** con las cargas de trabajo instaladas:
    ```powershell
    dotnet workload install wasm-tools
    ```
2.  **Flutter SDK (3.19.0 o superior)**: Soporte para `extension type`.
3.  **Android NDK**: Necesario para compilar librerías de Android. Asegúrate de tener configurada la variable `ANDROID_NDK_ROOT` o que el NDK esté en las rutas estándar.

---

## 2. Ejecución en la Web (Wasm)

### Compilación y Preparación
```powershell
# 1. Compilar C# para WebAssembly
cd wasm_logic
dotnet publish -r browser-wasm -c Release -p:DefineConstants=WEB_WASM

# 2. Mover archivos al proyecto Flutter
# Los archivos generados se encuentran en bin\Release\net8.0\browser-wasm\publish\
copy bin\Release\net8.0\browser-wasm\publish\* ..\flutter_app\web\
copy ..\web_bridge\loader.js ..\flutter_app\web\
```

### Lanzamiento
```powershell
cd ../flutter_app
flutter run -d chrome --release
```

---

## 3. Ejecución en Windows (Nativo)

### Compilación y Preparación
```powershell
# 1. Compilar C# como DLL Nativa
cd wasm_logic
dotnet publish -r win-x64 -c Release

# 2. Mover DLL a la carpeta de librerías de Flutter Windows
# La DLL se genera en bin\Release\net8.0\win-x64\publish\WasmLogic.dll
copy bin\Release\net8.0\win-x64\publish\WasmLogic.dll ..\flutter_app\windows\libs\
```

### Lanzamiento
```powershell
cd ../flutter_app
flutter run -d windows --release
```

---

## 4. Ejecución en Android (Nativo)

> [!IMPORTANT]
> **Requerimiento de Linux/WSL:** La compilación nativa para Android (`NativeAOT`) requiere un sistema operativo basado en **Linux** (como WSL o Ubuntu) para realizar el enlazado nativo.

### Compilación Automatizada (Recomendado)
Se ha incluido un script bash que automatiza todo el proceso (compilación y copia de archivos):

```bash
# Desde WSL o Linux en la raíz del proyecto:
chmod +x build_android.sh
./build_android.sh
```

### Compilación Manual (Desde WSL/Linux)
Si prefieres hacerlo manualmente:
```bash
# 1. Compilar C# para Android (Arm64)
cd wasm_logic
dotnet publish -r linux-bionic-arm64 -c Release -p:PublishAot=true -p:NativeLib=Shared

# 2. Mover librería .so a la carpeta JNI de Flutter
# El archivo se genera en bin/Release/net8.0/linux-bionic-arm64/publish/libWasmLogic.so
cp bin/Release/net8.0/linux-bionic-arm64/publish/libWasmLogic.so ../flutter_app/android/app/src/main/jniLibs/arm64-v8a/
```

### Lanzamiento (Desde Windows)
```powershell
cd flutter_app
flutter run -d android --release
```

---

## 5. Explicación Técnica de la Arquitectura

### Carga Condicional (Dart)
La aplicación utiliza un sistema de importación condicional en `main.dart` para evitar conflictos entre plataformas:
*   **Web**: Utiliza `dart:js_interop` para hablar con el puente JavaScript.
*   **Nativo (Windows/Android)**: Utiliza `dart:ffi` para cargar y ejecutar funciones directamente desde la memoria (DLL/.so).

### Interfaz Unificada
Ambas implementaciones exponen una clase `CalculatorService` con los mismos métodos (`init`, `isReady`, `add`), permitiendo que el código de la UI sea 100% idéntico e independiente de la plataforma.

---

## 6. Resolución de Problemas

*   **Error MIME en Web**: El servidor debe responder con `Content-Type: application/wasm`.
*   **DLL no encontrada**: En Windows, la DLL debe estar en `windows/libs/` o junto al `.exe`.
*   **Error de Enlazado en Android**: Si obtienes errores de símbolos no definidos (`_init`, `_fini`), asegúrate de que el archivo `.csproj` incluya el flag `--undefined-version` para el enlazador.
*   **Cross-OS Compilation**: Si intentas compilar para Android desde Windows, recibirás un error de .NET. Usa **WSL** para este paso específico.
