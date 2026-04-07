/**
 * loader.js - El puente de comunicación JavaScript (Glue Code).
 * Este archivo inicializa el runtime de .NET Wasm y expone la lógica a window.wasmBridge.
 */

import { dotnet } from './dotnet.js';

async function initWasm() {
  try {
    // Configuración inicial del motor de .NET.
    const { getAssemblyExports, getConfig } = await dotnet
      .withDiagnosticTracing(false)
      .withConfig({ disableIntegrityCheck: true })
      .create();

    const config = getConfig();
    // Accedemos a las funciones exportadas desde el ensamblado 'WasmLogic'.
    const exports = await getAssemblyExports(config.mainAssemblyName);

    // Creamos el puente global para que Dart pueda acceder a la lógica de C#.
    window.wasmBridge = {
      // Wrapper para la función de suma definida en Logic.cs
      sumar: (a, b) => {
        // Aseguramos que los parámetros sean enteros antes de llamar a C#.
        return exports.WasmLogic.Logic.Sumar(parseInt(a), parseInt(b));
      },
      // Bandera que indica que el módulo está cargado y listo.
      ready: true
    };

    // Notificación opcional por consola (útil para depuración minimalista).
    console.log("Wasm Bridge: .NET Runtime Ready");
    
    // Disparamos un evento personalizado para que Flutter pueda reaccionar a la carga.
    window.dispatchEvent(new CustomEvent('wasm-ready'));

  } catch (err) {
    console.error("Wasm Bridge: Error inicializando .NET Runtime", err);
  }
}

// Ejecutamos la inicialización asíncrona.
initWasm();
