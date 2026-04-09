# build_web.ps1 - Compilación y Sincronización Web (Wasm)
# Ejecutar desde la raíz del proyecto.

Write-Host ">>> Iniciando proceso de compilación Web (Wasm)..." -ForegroundColor Blue

# 1. Limpieza de directorios
Write-Host ">>> Limpiando binarios previos..." -ForegroundColor Yellow
cd wasm_logic
dotnet clean -c Release
if (Test-Path "bin") { Remove-Item -Recurse -Force bin }
if (Test-Path "obj") { Remove-Item -Recurse -Force obj }

# 2. Compilación .NET
Write-Host ">>> Ejecutando 'dotnet publish' para browser-wasm..." -ForegroundColor Blue
dotnet publish -r browser-wasm -c Release

if ($LASTEXITCODE -ne 0) {
    Write-Host ">>> ERROR: La compilación de .NET falló." -ForegroundColor Red
    exit $LASTEXITCODE
}

# 3. Definir rutas
$sourceDir = "bin/Release/net8.0/browser-wasm/AppBundle/_framework"
$destDir = "../flutter_app/web/_framework"

# 4. Sincronización de Archivos
Write-Host ">>> Sincronizando binarios con Flutter..." -ForegroundColor Green
if (-not (Test-Path $destDir)) { New-Item -ItemType Directory -Path $destDir -Force }

# Copiar todo el contenido de _framework
Copy-Item -Path "$sourceDir\*" -Destination $destDir -Recurse -Force

# Copiar el loader.js (puente)
Write-Host ">>> Copiando loader.js..." -ForegroundColor Green
Copy-Item -Path "../web_bridge/loader.js" -Destination "../flutter_app/web/loader.js" -Force

Write-Host "`n================================================================" -ForegroundColor Green
Write-Host "  ¡ÉXITO! Binarios Web actualizados." -ForegroundColor Green
Write-Host "  Ahora puedes ejecutar: cd flutter_app; flutter run -d chrome --release" -ForegroundColor Green
Write-Host "================================================================" -ForegroundColor Green
cd ..
