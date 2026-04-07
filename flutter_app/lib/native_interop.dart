import 'dart:ffi';
import 'dart:io';

/// native_interop.dart - Implementación NATIVA (Windows/Android).

typedef SumarNativeFunc = Int32 Function(Int32 a, Int32 b);
typedef SumarDartFunc = int Function(int a, int b);

class CalculatorService {
  late DynamicLibrary _dylib;
  late SumarDartFunc _sumar;

  // Método de inicialización común.
  void init() {
    if (Platform.isWindows) {
      _dylib = DynamicLibrary.open('WasmLogic.dll');
    } else if (Platform.isAndroid) {
      try {
        _dylib = DynamicLibrary.open('libWasmLogic.so');
      } catch (e) {
        print("FFI: Error cargando libWasmLogic.so, intentando fallback: $e");
        try {
          // A veces en Android el sistema prefiere el nombre sin prefijo/extensión para búsqueda en el path
          _dylib = DynamicLibrary.open('WasmLogic');
        } catch (e2) {
          rethrow;
        }
      }
    } else {
      throw UnsupportedError("Plataforma no soportada");
    }

    _sumar = _dylib.lookupFunction<SumarNativeFunc, SumarDartFunc>('sumar_nativo');
  }

  bool isReady() => true; // Nativo está listo tras init()

  int add(int a, int b) => _sumar(a, b);
}
