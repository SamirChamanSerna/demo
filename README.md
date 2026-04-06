# PoC: Flutter + C# NativeAOT (Multiplataforma)

Esta prueba de concepto demuestra cómo compartir lógica de negocio escrita en C# entre Flutter Web (WebAssembly), Windows (DLL) y Android (Librería Nativa .so).

---

## 1. Prerrequisitos Comunes

1.  **.NET 8 SDK** con las cargas de trabajo instaladas:
    ```powershell
    dotnet workload install wasm-tools
    ```
2.  **Flutter SDK (3.19.0 o superior)**: Soporte para `extension type`.
3.  **Android NDK**: Necesario para compilar librerías de Android.

---

## 2. Ejecución en la Web (Wasm)

### Compilación y Preparación
```powershell
# 1. Compilar C# para WebAssembly
cd wasm_logic
dotnet publish -r browser-wasm -c Release -p:DefineConstants=WEB_WASM

# 2. Mover archivos al proyecto Flutter
# Nota: La ruta de salida puede variar, buscar en bin\Release\net8.0\browser-wasm\publish\wwwroot\_framework
copy bin\Release\net8.0\browser-wasm\publish\wwwroot\_framework\* ..\flutter_app\web\
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
> **Limitación de Compilación Cruzada:** La compilación nativa para Android (`NativeAOT`) requiere un sistema operativo basado en **Linux** (como WSL o Ubuntu) para generar el archivo `.so`. .NET en Windows no soporta el enlazado nativo para objetivos Linux/Android.

### Compilación y Preparación (Desde WSL/Linux)
```bash
# 1. Compilar C# para Android (Arm64)
cd wasm_logic
dotnet publish -r android-arm64 -c Release

# 2. Mover librería .so a la carpeta JNI de Android en Windows
cp bin/Release/net8.0/android-arm64/publish/libWasmLogic.so /mnt/c/ruta/a/flutter_app/android/app/src/main/jniLibs/arm64-v8a/
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
*   **Cross-OS Compilation**: Si intentas compilar para Android desde Windows, recibirás un error de .NET. Usa **WSL** para este paso específico.
