import 'dart:async';
import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

// Importación Condicional: El compilador elige el archivo correcto.
import 'wasm_interop.dart' if (dart.library.io) 'native_interop.dart';

/// main.dart - Aplicación Multiplataforma Real (Híbrida).

void main() {
  runApp(const WasmApp());
}

class WasmApp extends StatelessWidget {
  const WasmApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      theme: ThemeData(useMaterial3: true, colorSchemeSeed: Colors.deepPurple),
      home: const WasmHome(),
    );
  }
}

class WasmHome extends StatefulWidget {
  const WasmHome({super.key});

  @override
  State<WasmHome> createState() => _WasmHomeState();
}

class _WasmHomeState extends State<WasmHome> {
  // Ahora usamos una única clase CalculatorService en todas las plataformas.
  final _service = CalculatorService();
  
  bool _hasStartedLoading = false;
  final _isReady = ValueNotifier<bool>(false);
  final _result = ValueNotifier<int?>(null);

  final _aController = TextEditingController();
  final _bController = TextEditingController();

  void _startEngine() {
    setState(() {
      _hasStartedLoading = true;
    });
    
    // Método común init() para Web e IAO.
    _service.init();
    
    if (kIsWeb) {
      _checkStatus();
    } else {
      // En Nativo, la DLL se carga de forma síncrona.
      _isReady.value = true;
    }
  }

  void _checkStatus() {
    Timer.periodic(const Duration(milliseconds: 200), (timer) {
      if (_service.isReady()) {
        _isReady.value = true;
        timer.cancel();
      }
    });
  }

  void _calculateSum() {
    final a = int.tryParse(_aController.text) ?? 0;
    final b = int.tryParse(_bController.text) ?? 0;
    _result.value = _service.add(a, b);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text("Flutter + C# (Web & Native)")),
      body: Center(
        child: ConstrainedBox(
          constraints: const BoxConstraints(maxWidth: 600),
          child: Padding(
            padding: const EdgeInsets.all(24.0),
            child: AnimatedSwitcher(
              duration: const Duration(milliseconds: 500),
              child: !_hasStartedLoading 
                ? _buildWelcomeScreen() 
                : _buildCalculatorScreen(),
            ),
          ),
        ),
      ),
    );
  }

  Widget _buildWelcomeScreen() {
    return Column(
      key: const ValueKey("Welcome"),
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        const Icon(Icons.devices, size: 80, color: Colors.indigo),
        const SizedBox(height: 24),
        const Text(
          "PoC Multiplataforma: ${kIsWeb ? "Web" : "Native"}",
          style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
          textAlign: TextAlign.center,
        ),
        const SizedBox(height: 16),
        const Text(
          "Lógica de negocio escrita en C#, compartida entre plataformas.",
          textAlign: TextAlign.center,
        ),
        const SizedBox(height: 48),
        ElevatedButton.icon(
          onPressed: _startEngine,
          icon: const Icon(Icons.rocket_launch),
          label: const Text("Iniciar Motor"),
          style: ElevatedButton.styleFrom(padding: const EdgeInsets.all(20)),
        ),
      ],
    );
  }

  Widget _buildCalculatorScreen() {
    const Color greenReady = Color(0xFF2E7D32);
    return Column(
      key: const ValueKey("Calculator"),
      children: [
        ValueListenableBuilder<bool>(
          valueListenable: _isReady,
          builder: (context, ready, child) {
            return ready 
              ? const Card(
                  color: greenReady,
                  child: Padding(
                    padding: EdgeInsets.all(12.0),
                    child: Text("Motor C# (NativeAOT): ACTIVO", style: TextStyle(color: Colors.white)),
                  ),
                )
              : const Column(
                  children: [
                    CircularProgressIndicator(),
                    SizedBox(height: 16),
                    Text("Cargando motor de C#..."),
                  ],
                );
          },
        ),
        const SizedBox(height: 32),
        TextField(
          controller: _aController,
          decoration: const InputDecoration(labelText: "Número A", border: OutlineInputBorder()),
          keyboardType: TextInputType.number,
          inputFormatters: [FilteringTextInputFormatter.digitsOnly],
        ),
        const SizedBox(height: 16),
        TextField(
          controller: _bController,
          decoration: const InputDecoration(labelText: "Número B", border: OutlineInputBorder()),
          keyboardType: TextInputType.number,
          inputFormatters: [FilteringTextInputFormatter.digitsOnly],
        ),
        const SizedBox(height: 32),
        ValueListenableBuilder<bool>(
          valueListenable: _isReady,
          builder: (context, ready, child) {
            return ElevatedButton(
              onPressed: ready ? _calculateSum : null,
              style: ElevatedButton.styleFrom(minimumSize: const Size.fromHeight(50)),
              child: const Text("Calcular Suma en C#"),
            );
          },
        ),
        const SizedBox(height: 48),
        ValueListenableBuilder<int?>(
          valueListenable: _result,
          builder: (context, result, child) {
            return Text(
              result == null ? "Resultado: --" : "Resultado de C#: $result",
              style: Theme.of(context).textTheme.headlineMedium,
            );
          },
        ),
      ],
    );
  }
}
