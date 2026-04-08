#!/bin/bash

# ==============================================================================
# Script de Compilación NativeAOT para Android (Optimizado)
# Uso: ./build_android.sh [arm64|x64]
# ==============================================================================

# Colores
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m'

# 1. Determinar Arquitectura (por defecto arm64)
ARCH="${1:-arm64}"

if [ "$ARCH" == "x64" ]; then
    RUNTIME_ID="linux-bionic-x64"
    JNI_DIR="x86_64"
    echo -e "${BLUE}>>> Configurando para EMULADOR (x86_64)...${NC}"
else
    RUNTIME_ID="linux-bionic-arm64"
    JNI_DIR="arm64-v8a"
    echo -e "${BLUE}>>> Configurando para DISPOSITIVO REAL (arm64-v8a)...${NC}"
fi

# 2. Definir rutas
PROJECT_DIR="./wasm_logic"
FLUTTER_JNILIBS_DIR="./flutter_app/android/app/src/main/jniLibs/$JNI_DIR"
OUTPUT_FILE="libWasmLogic.so"

# 3. Buscar y Exportar NDK (Crucial para .NET)
if [ -z "$ANDROID_NDK_ROOT" ]; then
    NDK_SEARCH_PATHS=(
        "$HOME/Android/Sdk/ndk-bundle"
        "$HOME/Android/Sdk/ndk/$(ls $HOME/Android/Sdk/ndk 2>/dev/null | sort -V | tail -n 1)"
        "/usr/local/lib/android/sdk/ndk-bundle"
        "$HOME/AppData/Local/Android/Sdk/ndk/$(ls $HOME/AppData/Local/Android/Sdk/ndk 2>/dev/null | sort -V | tail -n 1)" # Para algunos casos WSL
    )
    for path in "${NDK_SEARCH_PATHS[@]}"; do
        if [ -d "$path" ]; then
            export ANDROID_NDK_ROOT="$path"
            export AndroidNdkPath="$path"
            echo -e "${YELLOW}>>> NDK detectado en: $path${NC}"
            break
        fi
    done
fi

if [ -z "$ANDROID_NDK_ROOT" ]; then
    echo -e "${RED}>>> ERROR: No se encontró el Android NDK. Instálalo o define ANDROID_NDK_ROOT.${NC}"
    exit 1
fi

# 4. Limpieza previa para evitar confusiones
rm -rf "$PROJECT_DIR/bin/publish-android-$ARCH"
mkdir -p "$FLUTTER_JNILIBS_DIR"

# 5. Compilar
echo -e "${BLUE}>>> Ejecutando 'dotnet publish' para $RUNTIME_ID...${NC}"

dotnet publish "$PROJECT_DIR" \
    -c Release \
    -r "$RUNTIME_ID" \
    --self-contained true \
    -o "$PROJECT_DIR/bin/publish-android-$ARCH"

if [ $? -ne 0 ]; then
    echo -e "${RED}>>> ERROR: La compilación de .NET falló.${NC}"
    exit 1
fi

# 6. Localizar y copiar el binario
# El compilador suele generar WasmLogic.so, lo renombramos a libWasmLogic.so para Android
SOURCE_SO=$(find "$PROJECT_DIR/bin/publish-android-$ARCH" -name "*.so" | head -n 1)

if [ -z "$SOURCE_SO" ]; then
    echo -e "${RED}>>> ERROR: No se encontró el archivo .so generado.${NC}"
    exit 1
fi

cp "$SOURCE_SO" "$FLUTTER_JNILIBS_DIR/$OUTPUT_FILE"

if [ -f "$FLUTTER_JNILIBS_DIR/$OUTPUT_FILE" ]; then
    echo -e "${GREEN}================================================================${NC}"
    echo -e "${GREEN}  ¡ÉXITO! Archivo copiado a Flutter.${NC}"
    echo -e "${GREEN}  Arquitectura: $ARCH ($JNI_DIR)${NC}"
    echo -e "${GREEN}  Ruta: $FLUTTER_JNILIBS_DIR/$OUTPUT_FILE${NC}"
    echo -e "${GREEN}================================================================${NC}"
else
    echo -e "${RED}>>> ERROR: Falló la copia final.${NC}"
    exit 1
fi