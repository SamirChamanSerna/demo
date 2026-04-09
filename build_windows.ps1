# build_windows.ps1 - Compilación y Sincronización Windows (NativeAOT)
# Ejecutar desde la raíz del proyecto.

Write-Host ">>> Iniciando proceso de compilación Windows (NativeAOT)..." -ForegroundColor Blue

# 1. Limpieza de directorios
Write-Host ">>> Limpiando binarios previos..." -ForegroundColor Yellow
cd wasm_logic
dotnet clean -c Release
if (Test-Path "bin") { Remove-Item -Recurse -Force bin }
if (Test-Path "obj") { Remove-Item -Recurse -Force obj }

# 2. Compilación .NET
Write-Host ">>> Ejecutando 'dotnet publish' para win-x64..." -ForegroundColor Blue
dotnet publish -r win-x64 -c Release

if ($LASTEXITCODE -ne 0) {
    Write-Host ">>> ERROR: La compilación de .NET falló." -ForegroundColor Red
    exit $LASTEXITCODE
}

# 3. Definir rutas
$sourceFile = "bin/Release/net8.0/win-x64/publish/WasmLogic.dll"
$destDir = "../flutter_app/windows/libs"

# 4. Sincronización de Archivos
Write-Host ">>> Sincronizando DLL nativa con Flutter..." -ForegroundColor Green
if (-not (Test-Path $destDir)) { New-Item -ItemType Directory -Path $destDir -Force }

Copy-Item -Path $sourceFile -Destination $destDir -Force

Write-Host "`n================================================================" -ForegroundColor Green
Write-Host "  ¡ÉXITO! DLL de Windows actualizada." -ForegroundColor Green
Write-Host "  Ahora puedes ejecutar: cd flutter_app; flutter run -d windows --release" -ForegroundColor Green
Write-Host "================================================================" -ForegroundColor Green
cd ..
