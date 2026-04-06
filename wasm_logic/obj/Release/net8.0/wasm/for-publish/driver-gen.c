#include <mono/jit/jit.h>
extern void *mono_aot_module_WasmLogic_info;
extern void *mono_aot_module_System_Runtime_InteropServices_JavaScript_info;
extern void *mono_aot_module_System_Private_CoreLib_info;
extern void *mono_aot_module_aot_instances_info;
void register_aot_modules (void);
void register_aot_modules (void)
{
	mono_aot_register_module (mono_aot_module_WasmLogic_info);
	mono_aot_register_module (mono_aot_module_System_Runtime_InteropServices_JavaScript_info);
	mono_aot_register_module (mono_aot_module_System_Private_CoreLib_info);
	mono_aot_register_module (mono_aot_module_aot_instances_info);
}
#define EE_MODE_LLVMONLY_INTERP 1
