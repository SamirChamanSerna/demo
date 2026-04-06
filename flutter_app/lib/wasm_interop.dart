import 'dart:js_interop';
import 'package:web/web.dart' as web;

/**
 * wasm_interop.dart - Implementación WEB.
 */

@JS('wasmBridge')
external JSAny? get wasmBridge;

extension type WasmBridge(JSObject _) implements JSObject {
  external bool get ready;
  external JSNumber sumar(JSNumber a, JSNumber b);
}

class CalculatorService {
  // Método de inicialización común.
  void init() {
    final script = web.document.createElement('script') as web.HTMLScriptElement;
    script.type = 'module';
    script.src = 'loader.js';
    web.document.head!.append(script);
  }

  static WasmBridge? get _bridge {
    if (wasmBridge.isUndefinedOrNull) return null;
    return wasmBridge as WasmBridge;
  }

  bool isReady() => _bridge?.ready ?? false;

  int add(int a, int b) {
    final bridge = _bridge;
    if (bridge == null) throw Exception("Wasm Bridge no listo");
    return bridge.sumar(a.toJS, b.toJS).toDartInt;
  }
}
