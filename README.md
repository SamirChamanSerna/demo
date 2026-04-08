# Prueba de Concepto: Lógica C# Compartida (Wasm + NativeAOT)

Esta prueba de concepto demuestra cómo compartir lógica de negocio escrita en C# entre Flutter Web (WebAssembly), Windows (DLL Nativa) y Android (Librería Nativa .so) utilizando **.NET 8**.

---

## 1. Prerrequisitos Comunes

1.  **.NET 8 SDK** instalado.
2.  **Cargas de trabajo WASM**:
    ```bash
    dotnet workload install wasm-tools
    ```
3.  **Flutter SDK (3.19.0 o superior)**.
4.  **Android NDK**: Necesario para compilar librerías de Android. 
    *   En Linux/WSL, asegúrate de tener instalada una versión del NDK (ej. 25.x o 26.x).
5.  **WSL (Windows Subsystem for Linux)**: Requerido para compilar las librerías de Android desde Windows.

---

## 2. Ejecución en la Web (Wasm)

El archivo `.csproj` detecta automáticamente la plataforma y aplica las optimizaciones de tamaño.

### Compilación
```bash
cd wasm_logic
dotnet publish -r browser-wasm -c Release

# Los archivos generados están en: bin/Release/net8.0/browser-wasm/publish/wwwroot/_framework/
```

### Preparación y Lanzamiento
1. Copia los archivos `.wasm` generados a la carpeta `web/` de tu proyecto Flutter.
2. Copia el archivo `loader.js` (si posees uno personalizado) a la misma carpeta.
3. Ejecuta Flutter:
   ```bash
   cd ../flutter_app
   flutter run -d chrome --release
   ```

---

## 3. Ejecución en Windows (NativeAOT)

Genera una DLL nativa que no requiere el runtime de .NET instalado en la máquina destino.

### Compilación
```bash
cd wasm_logic
dotnet publish -r win-x64 -c Release
```

### Preparación
1. Localiza el archivo `WasmLogic.dll` en `bin/Release/net8.0/win-x64/publish/`.
2. Cópialo a `flutter_app/windows/libs/`.
3. Ejecuta Flutter:
   ```bash
   cd ../flutter_app
   flutter run -d windows --release
   ```

---

## 4. Ejecución en Android (NativeAOT)

> [!IMPORTANT]
> **WSL Requerido:** La compilación para Android debe realizarse en un entorno Linux (WSL es suficiente) debido a que el enlazador nativo de .NET para Android usa bibliotecas de Bionic/Linux.

### Compilación Automatizada (Recomendado)
El script `build_android.sh` detecta el NDK automáticamente, compila y mueve los archivos a la carpeta correcta de Flutter.

**Para Dispositivo Físico (ARM64):**
```bash
chmod +x build_android.sh
./build_android.sh arm64
```

**Para Emulador de Android en Windows (x86_64):**
```bash
./build_android.sh x64
```

### Compilación Manual
Si deseas compilar manualmente desde la terminal de WSL:
```bash
# Android ARM64
dotnet publish -r linux-bionic-arm64 -c Release

# Android x64 (Emulador)
dotnet publish -r linux-bionic-x64 -c Release
```

---

## 5. Tabla de Arquitecturas soportadas

| Plataforma | Runtime Identifier (RID) | Salida | Destino en Flutter |
| :--- | :--- | :--- | :--- |
| **Web** | `browser-wasm` | `.wasm` | `web/` |
| **Windows** | `win-x64` | `.dll` | `windows/libs/` |
| **Android (Físico)** | `linux-bionic-arm64` | `libWasmLogic.so` | `jniLibs/arm64-v8a/` |
| **Android (Emulador)**| `linux-bionic-x64` | `libWasmLogic.so` | `jniLibs/x86_64/` |

---

## 6. Notas Técnicas y Resolución de Problemas

*   **Error `PrivateSdkAssemblies`**: Este error suele ocurrir si intentas usar `PublishAot` en WebAssembly. El `.csproj` actual corrige esto desactivando `PublishAot` automáticamente cuando el target es `browser-wasm`.
*   **Compatibilidad de Emulador**: Los emuladores estándar de Android en Windows corren sobre arquitectura **x86_64**. No intentes cargar la librería `arm64` en el emulador, ya que Flutter lanzará un error de "Invalid ELF header" o simplemente no encontrará la librería.
*   **Android NDK**: Si el script no encuentra el NDK, exporta la ruta manualmente en tu terminal de WSL:
    ```bash
    export ANDROID_NDK_ROOT=/ruta/a/tu/android-sdk/ndk/version
    ```
*   **Trimming**: Se ha configurado `TrimMode=full` para reducir drásticamente el tamaño de los binarios. Si usas librerías externas que dependan de mucha reflexión, podrías necesitar añadir un archivo `TrimmerDescriptor`.

---