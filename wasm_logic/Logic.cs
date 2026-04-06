using System.Runtime.InteropServices;

#if WEB_WASM
using System.Runtime.InteropServices.JavaScript;
#endif

namespace WasmLogic;

public partial class Logic
{
    // --- Lógica de Negocio Unificada ---
    private static int SumarInterno(int a, int b) => a + b;

    // --- Exportación WEB (JavaScript) ---
#if WEB_WASM
    [JSExport]
    public static int Sumar(int a, int b) => SumarInterno(a, b);
#endif

    // --- Exportación NATIVA (Windows/Android/Linux) ---
    // UnmanagedCallersOnly permite que Flutter FFI llame directamente a la DLL/SO.
    [UnmanagedCallersOnly(EntryPoint = "sumar_nativo")]
    public static int SumarNativo(int a, int b) => SumarInterno(a, b);

    // Punto de entrada obligatorio
    public static void Main() { }
}
