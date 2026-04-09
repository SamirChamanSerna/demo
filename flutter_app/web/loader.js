/**
 * loader.js - El puente de comunicación JavaScript (Glue Code).
 * Este archivo inicializa el runtime de .NET Wasm y expone la lógica a window.wasmBridge.
 */

import { dotnet } from './_framework/dotnet.js';

async function initWasm() {
  console.log("Wasm Bridge: Starting initialization...");
  try {
    // Configuración inicial del motor de .NET.
    const { getAssemblyExports, getConfig } = await dotnet
      .withDiagnosticTracing(false)
      .create();

    console.log("Wasm Bridge: .NET Runtime created.");

    const config = getConfig();
    console.log("Wasm Bridge: Loading assembly exports for", config.mainAssemblyName);
    
    // Accedemos a las funciones exportadas desde el ensamblado 'WasmLogic'.
    const exports = await getAssemblyExports(config.mainAssemblyName);

    // Creamos el puente global para que Dart pueda acceder a la lógica de C#.
    window.wasmBridge = {
      // Wrapper para la función de suma definida en Logic.cs
      sumar: (a, b) => {
        try {
          return exports.WasmLogic.Logic.Sumar(parseInt(a), parseInt(b));
        } catch (sumErr) {
          console.error("Wasm Bridge: Error calling Sumar", sumErr);
          throw sumErr;
        }
      },
      // Bandera que indica que el módulo está cargado y listo.
      ready: true
    };

    console.log("Wasm Bridge: .NET Runtime Ready and window.wasmBridge initialized.");
    
    // Disparamos un evento personalizado para que Flutter pueda reaccionar a la carga.
    window.dispatchEvent(new CustomEvent('wasm-ready'));

  } catch (err) {
    console.error("Wasm Bridge: Error inicializando .NET Runtime", err);
  }
}

// Ejecutamos la inicialización asíncrona.
initWasm();
