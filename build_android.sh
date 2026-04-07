#!/bin/bash

# ==============================================================================
# Script de Compilación NativeAOT para Android (WSL)
# Genera libWasmLogic.so y lo mueve al directorio jniLibs de Flutter
# ==============================================================================

# Colores para la terminal
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${BLUE}>>> Iniciando proceso de compilación para ANDROID (arm64-v8a)...${NC}"

# 1. Definir rutas
PROJECT_DIR="./wasm_logic"
FLUTTER_JNILIBS_DIR="./flutter_app/android/app/src/main/jniLibs/arm64-v8a"
RUNTIME_ID="linux-bionic-arm64"
OUTPUT_FILE="libWasmLogic.so"

# Asegurar que el directorio de salida existe en Flutter
if [ ! -d "$FLUTTER_JNILIBS_DIR" ]; then
    echo -e "${YELLOW}!!! El directorio de jniLibs no existe. Creándolo...${NC}"
    mkdir -p "$FLUTTER_JNILIBS_DIR"
fi

# 2. Compilar con .NET (NativeAOT)
echo -e "${BLUE}>>> Ejecutando 'dotnet publish' para $RUNTIME_ID...${NC}"
echo -e "${YELLOW}>>> (Esto puede tardar un momento debido a la optimización de NativeAOT)${NC}"

# Si el NDK está instalado pero no en el PATH, intenta buscarlo en rutas comunes de WSL/Linux
if [ -z "$ANDROID_NDK_ROOT" ] && [ -z "$AndroidNdkPath" ]; then
    NDK_SEARCH_PATHS=(
        "$HOME/Android/Sdk/ndk-bundle"
        "$HOME/Android/Sdk/ndk/$(ls $HOME/Android/Sdk/ndk 2>/dev/null | sort -V | tail -n 1)"
        "/usr/local/lib/android/sdk/ndk-bundle"
        "/usr/lib/android-sdk/ndk-bundle"
    )
    for path in "${NDK_SEARCH_PATHS[@]}"; do
        if [ -d "$path" ]; then
            export AndroidNdkPath="$path"
            echo -e "${YELLOW}>>> NDK encontrado en: $path${NC}"
            break
        fi
    done
fi

if [ -z "$AndroidNdkPath" ] && [ -z "$ANDROID_NDK_ROOT" ]; then
    echo -e "${RED}>>> ADVERTENCIA: No se encontró el Android NDK (ANDROID_NDK_ROOT).${NC}"
    echo -e "${RED}>>> Es posible que el enlazado nativo falle si no está instalado.${NC}"
fi

dotnet publish "$PROJECT_DIR" \
    -c Release \
    -r "$RUNTIME_ID" \
    --self-contained true \
    -p:PublishAot=true \
    -p:NativeLib=Shared \
    -p:LinkerFlavor=lld \
    -o "$PROJECT_DIR/bin/publish-android"

# Verificar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo -e "${GREEN}>>> ¡Compilación exitosa!${NC}"
else
    echo -e "${RED}>>> ERROR: La compilación de .NET falló.${NC}"
    exit 1
fi

# 3. Localizar y copiar el binario
# Nota: .NET puede generar WasmLogic.so o libWasmLogic.so dependiendo de la configuración.
# Buscamos el archivo .so generado en la carpeta de salida.
SOURCE_SO=$(find "$PROJECT_DIR/bin/publish-android" -name "*.so" | head -n 1)

if [ -z "$SOURCE_SO" ]; then
    echo -e "${RED}>>> ERROR: No se encontró ningún archivo .so en el directorio de salida.${NC}"
    exit 1
fi

echo -e "${BLUE}>>> Archivo encontrado: $(basename "$SOURCE_SO")${NC}"
echo -e "${BLUE}>>> Copiando a: $FLUTTER_JNILIBS_DIR/$OUTPUT_FILE${NC}"

cp "$SOURCE_SO" "$FLUTTER_JNILIBS_DIR/$OUTPUT_FILE"

# 4. Resultado final
if [ -f "$FLUTTER_JNILIBS_DIR/$OUTPUT_FILE" ]; then
    echo -e "${GREEN}================================================================${NC}"
    echo -e "${GREEN}  ¡PROCESO COMPLETADO CON ÉXITO!${NC}"
    echo -e "${GREEN}  Binario: $OUTPUT_FILE${NC}"
    echo -e "${GREEN}  Destino: $FLUTTER_JNILIBS_DIR${NC}"
    echo -e "${GREEN}================================================================${NC}"
    echo -e "${YELLOW}Ahora puedes ejecutar 'flutter run' en tu dispositivo Android.${NC}"
else
    echo -e "${RED}>>> ERROR: No se pudo verificar la copia del archivo final.${NC}"
    exit 1
fi
