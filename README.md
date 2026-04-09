# Prueba de Concepto: Lógica C# Compartida (Wasm + NativeAOT)

Esta prueba de concepto demuestra cómo compartir lógica de negocio escrita en C# entre Flutter Web (WebAssembly), Windows (DLL Nativa) y Android (Librería Nativa .so) utilizando **.NET 8**.

---

## 1. Prerrequisitos Comunes

1.  **.NET 8 SDK** instalado.
2.  **Cargas de trabajo WASM**:
    ```powershell
    dotnet workload install wasm-tools
    ```
3.  **Flutter SDK (3.19.0 o superior)**.
4.  **Android NDK**: Necesario para compilar librerías de Android.
5.  **WSL (Windows Subsystem for Linux)**: Requerido para compilar las librerías de Android desde Windows (usando el script `.sh`).

---

## 2. Automatización de Compilación (Recomendado)

He incluido scripts de PowerShell para simplificar el proceso de limpieza, compilación y despliegue de binarios.

### 🌐 Web (Wasm)
Desde la raíz del proyecto, ejecuta:
```powershell
.\build_web.ps1
```
*Este script limpia los binarios previos, compila para `browser-wasm`, sincroniza el `_framework` y el `loader.js` en la carpeta `flutter_app/web/`.*

### 🪟 Windows (NativeAOT)
Desde la raíz del proyecto, ejecuta:
```powershell
.\build_windows.ps1
```
*Este script compila la lógica en una DLL nativa y la coloca en `flutter_app/windows/libs/`.*

### 🤖 Android (NativeAOT)
Requiere WSL. Desde una terminal Linux/WSL:
```bash
chmod +x build_android.sh
./build_android.sh arm64  # Para dispositivos reales
./build_android.sh x64    # Para emuladores
```

---

## 3. Estructura de Carpetas y Binarios

| Plataforma | Origen de Compilación (.NET) | Destino en Flutter |
| :--- | :--- | :--- |
| **Web** | `wasm_logic/.../AppBundle/_framework/` | `flutter_app/web/_framework/` |
| **Windows** | `wasm_logic/.../win-x64/publish/WasmLogic.dll` | `flutter_app/windows/libs/` |
| **Android** | `wasm_logic/.../publish-android-*/libWasmLogic.so` | `flutter_app/android/app/src/main/jniLibs/` |

---

## 4. Ejecución de la App Flutter

Una vez que los binarios están sincronizados:

```bash
cd flutter_app
# Para Web
flutter run -d chrome --release
# Para Windows
flutter run -d windows --release
# Para Android
flutter run -d <device_id> --release
```

---

## 5. Notas Técnicas y Resolución de Problemas

*   **Integridad SRI (Web)**: Si realizas cambios en C# y los copias manualmente, podrías ver errores de "Integrity check failed". El script `build_web.ps1` ayuda a mantener la consistencia, y el `loader.js` está configurado con `disableIntegrityCheck: true` para evitar bloqueos del navegador.
*   **Archivos de Soporte (Web)**: Asegúrate de que la carpeta `_framework/supportFiles` se copie íntegramente, ya que contiene el archivo `0_runtimeconfig.bin` necesario para el inicio del runtime.
*   **Arquitecturas de Android**: Los emuladores de Android en Windows usan **x86_64**. Asegúrate de compilar con `./build_android.sh x64` para probar en el emulador.
*   **Trimming**: Se usa `TrimMode=full`. Si añades librerías externas que fallen al ejecutar (pero no al compilar), es probable que necesites configurar excepciones de recortes en el `.csproj`.
