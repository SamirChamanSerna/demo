#define ICALL_TABLE_corlib 1

static int corlib_icall_indexes [] = {
183,
191,
192,
193,
194,
195,
196,
197,
199,
200,
229,
230,
231,
249,
250,
253,
254,
255,
256,
316,
317,
320,
347,
348,
350,
352,
354,
356,
361,
369,
370,
371,
372,
373,
374,
375,
376,
377,
448,
449,
500,
505,
508,
510,
515,
516,
518,
519,
523,
524,
526,
528,
529,
532,
533,
534,
537,
539,
541,
543,
552,
604,
606,
608,
618,
619,
620,
622,
628,
629,
630,
631,
632,
640,
641,
642,
646,
647,
649,
651,
778,
922,
923,
4302,
4303,
4305,
4306,
4307,
4308,
4310,
4312,
4314,
4319,
4321,
4325,
4327,
4329,
4380,
4381,
4383,
4384,
4385,
4386,
4387,
4389,
4391,
4877,
4880,
4882,
4883,
4884,
5053,
5054,
5055,
5071,
5072,
5073,
5109,
5170,
5172,
5180,
5181,
5182,
5183,
5319,
5321,
5341,
5355,
5361,
5368,
5379,
5382,
5398,
5470,
5472,
5478,
5486,
5504,
5505,
5513,
5515,
5521,
5522,
5525,
5529,
5535,
5536,
5543,
5545,
5556,
5559,
5560,
5561,
5571,
5579,
5584,
5585,
5586,
5602,
5604,
5616,
5652,
5674,
5675,
6064,
6117,
6118,
6248,
6249,
6253,
6256,
6312,
6608,
6618,
6913,
6934,
6936,
6938,
};
void ves_icall_System_Array_InternalCreate (int,int,int,int,int);
int ves_icall_System_Array_GetCorElementTypeOfElementTypeInternal (int);
int ves_icall_System_Array_CanChangePrimitive (int,int,int);
int ves_icall_System_Array_FastCopy (int,int,int,int,int);
int ves_icall_System_Array_GetLengthInternal_raw (int,int,int);
int ves_icall_System_Array_GetLowerBoundInternal_raw (int,int,int);
void ves_icall_System_Array_GetGenericValue_icall (int,int,int);
void ves_icall_System_Array_GetValueImpl_raw (int,int,int,int);
void ves_icall_System_Array_SetValueImpl_raw (int,int,int,int);
void ves_icall_System_Array_SetValueRelaxedImpl_raw (int,int,int,int);
void ves_icall_System_Runtime_RuntimeImports_ZeroMemory (int,int);
void ves_icall_System_Runtime_RuntimeImports_Memmove (int,int,int);
void ves_icall_System_Buffer_BulkMoveWithWriteBarrier (int,int,int,int);
int ves_icall_System_Delegate_CreateDelegate_internal_raw (int,int,int,int,int);
int ves_icall_System_Delegate_GetVirtualMethod_internal_raw (int,int);
void ves_icall_System_Enum_GetEnumValuesAndNames_raw (int,int,int,int);
void ves_icall_System_Enum_InternalBoxEnum_raw (int,int,int64_t,int);
int ves_icall_System_Enum_InternalGetCorElementType (int);
void ves_icall_System_Enum_InternalGetUnderlyingType_raw (int,int,int);
int ves_icall_System_Environment_get_ProcessorCount ();
int ves_icall_System_Environment_get_TickCount ();
void ves_icall_System_Environment_FailFast_raw (int,int,int,int);
void ves_icall_System_GC_register_ephemeron_array_raw (int,int);
int ves_icall_System_GC_get_ephemeron_tombstone_raw (int);
void ves_icall_System_GC_SuppressFinalize_raw (int,int);
void ves_icall_System_GC_ReRegisterForFinalize_raw (int,int);
void ves_icall_System_GC_GetGCMemoryInfo (int,int,int,int,int,int);
int ves_icall_System_GC_AllocPinnedArray_raw (int,int,int);
int ves_icall_System_Object_MemberwiseClone_raw (int,int);
double ves_icall_System_Math_Ceiling (double);
double ves_icall_System_Math_Cos (double);
double ves_icall_System_Math_Floor (double);
double ves_icall_System_Math_Log10 (double);
double ves_icall_System_Math_Pow (double,double);
double ves_icall_System_Math_Sin (double);
double ves_icall_System_Math_Sqrt (double);
double ves_icall_System_Math_Tan (double);
double ves_icall_System_Math_ModF (double,int);
void ves_icall_RuntimeMethodHandle_ReboxFromNullable_raw (int,int,int);
void ves_icall_RuntimeMethodHandle_ReboxToNullable_raw (int,int,int,int);
int ves_icall_RuntimeType_GetCorrespondingInflatedMethod_raw (int,int,int);
void ves_icall_RuntimeType_make_array_type_raw (int,int,int,int);
void ves_icall_RuntimeType_make_byref_type_raw (int,int,int);
void ves_icall_RuntimeType_make_pointer_type_raw (int,int,int);
void ves_icall_RuntimeType_MakeGenericType_raw (int,int,int,int);
int ves_icall_RuntimeType_GetMethodsByName_native_raw (int,int,int,int,int);
int ves_icall_RuntimeType_GetPropertiesByName_native_raw (int,int,int,int,int);
int ves_icall_RuntimeType_GetConstructors_native_raw (int,int,int);
int ves_icall_System_RuntimeType_CreateInstanceInternal_raw (int,int);
void ves_icall_System_RuntimeType_AllocateValueType_raw (int,int,int,int);
void ves_icall_RuntimeType_GetDeclaringMethod_raw (int,int,int);
void ves_icall_System_RuntimeType_getFullName_raw (int,int,int,int,int);
void ves_icall_RuntimeType_GetGenericArgumentsInternal_raw (int,int,int,int);
int ves_icall_RuntimeType_GetGenericParameterPosition (int);
int ves_icall_RuntimeType_GetEvents_native_raw (int,int,int,int);
int ves_icall_RuntimeType_GetFields_native_raw (int,int,int,int,int);
void ves_icall_RuntimeType_GetInterfaces_raw (int,int,int);
void ves_icall_RuntimeType_GetDeclaringType_raw (int,int,int);
void ves_icall_RuntimeType_GetName_raw (int,int,int);
void ves_icall_RuntimeType_GetNamespace_raw (int,int,int);
int ves_icall_RuntimeType_FunctionPointerReturnAndParameterTypes_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetAttributes (int);
int ves_icall_RuntimeTypeHandle_GetMetadataToken_raw (int,int);
void ves_icall_RuntimeTypeHandle_GetGenericTypeDefinition_impl_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_GetCorElementType (int);
int ves_icall_RuntimeTypeHandle_HasInstantiation (int);
int ves_icall_RuntimeTypeHandle_IsInstanceOfType_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_HasReferences_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetArrayRank_raw (int,int);
void ves_icall_RuntimeTypeHandle_GetAssembly_raw (int,int,int);
void ves_icall_RuntimeTypeHandle_GetElementType_raw (int,int,int);
void ves_icall_RuntimeTypeHandle_GetModule_raw (int,int,int);
void ves_icall_RuntimeTypeHandle_GetBaseType_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_type_is_assignable_from_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_IsGenericTypeDefinition (int);
int ves_icall_RuntimeTypeHandle_GetGenericParameterInfo_raw (int,int);
int ves_icall_RuntimeTypeHandle_is_subclass_of_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_IsByRefLike_raw (int,int);
void ves_icall_System_RuntimeTypeHandle_internal_from_name_raw (int,int,int,int,int,int);
int ves_icall_System_String_FastAllocateString_raw (int,int);
int ves_icall_System_Type_internal_from_handle_raw (int,int);
int ves_icall_System_ValueType_InternalGetHashCode_raw (int,int,int);
int ves_icall_System_ValueType_Equals_raw (int,int,int,int);
int ves_icall_System_Threading_Interlocked_CompareExchange_Int (int,int,int);
void ves_icall_System_Threading_Interlocked_CompareExchange_Object (int,int,int,int);
int ves_icall_System_Threading_Interlocked_Decrement_Int (int);
int ves_icall_System_Threading_Interlocked_Increment_Int (int);
int ves_icall_System_Threading_Interlocked_Exchange_Int (int,int);
void ves_icall_System_Threading_Interlocked_Exchange_Object (int,int,int);
int64_t ves_icall_System_Threading_Interlocked_CompareExchange_Long (int,int64_t,int64_t);
int64_t ves_icall_System_Threading_Interlocked_Exchange_Long (int,int64_t);
int ves_icall_System_Threading_Interlocked_Add_Int (int,int);
void ves_icall_System_Threading_Monitor_Monitor_Enter_raw (int,int);
void mono_monitor_exit_icall_raw (int,int);
void ves_icall_System_Threading_Monitor_Monitor_pulse_all_raw (int,int);
int ves_icall_System_Threading_Monitor_Monitor_wait_raw (int,int,int,int);
void ves_icall_System_Threading_Monitor_Monitor_try_enter_with_atomic_var_raw (int,int,int,int,int);
void ves_icall_System_Threading_Thread_InitInternal_raw (int,int);
int ves_icall_System_Threading_Thread_GetCurrentThread ();
void ves_icall_System_Threading_InternalThread_Thread_free_internal_raw (int,int);
int ves_icall_System_Threading_Thread_GetState_raw (int,int);
void ves_icall_System_Threading_Thread_SetState_raw (int,int,int);
void ves_icall_System_Threading_Thread_ClrState_raw (int,int,int);
void ves_icall_System_Threading_Thread_SetName_icall_raw (int,int,int,int);
int ves_icall_System_Threading_Thread_YieldInternal ();
void ves_icall_System_Threading_Thread_SetPriority_raw (int,int,int);
void ves_icall_System_Runtime_Loader_AssemblyLoadContext_PrepareForAssemblyLoadContextRelease_raw (int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_GetLoadContextForAssembly_raw (int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFile_raw (int,int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalInitializeNativeALC_raw (int,int,int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFromStream_raw (int,int,int,int,int,int);
int ves_icall_System_GCHandle_InternalAlloc_raw (int,int,int);
void ves_icall_System_GCHandle_InternalFree_raw (int,int);
int ves_icall_System_GCHandle_InternalGet_raw (int,int);
int ves_icall_System_Runtime_InteropServices_Marshal_GetLastPInvokeError ();
void ves_icall_System_Runtime_InteropServices_Marshal_SetLastPInvokeError (int);
void ves_icall_System_Runtime_InteropServices_Marshal_StructureToPtr_raw (int,int,int,int);
int ves_icall_System_Runtime_InteropServices_NativeLibrary_LoadByName_raw (int,int,int,int,int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalGetHashCode_raw (int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalTryGetHashCode_raw (int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetUninitializedObjectInternal_raw (int,int);
void ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray_raw (int,int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetSpanDataFrom_raw (int,int,int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_SufficientExecutionStack ();
int ves_icall_System_Reflection_Assembly_GetEntryAssembly_raw (int);
int ves_icall_System_Reflection_Assembly_InternalLoad_raw (int,int,int,int);
int ves_icall_System_Reflection_AssemblyName_GetNativeName (int);
int ves_icall_MonoCustomAttrs_GetCustomAttributesInternal_raw (int,int,int,int);
int ves_icall_MonoCustomAttrs_GetCustomAttributesDataInternal_raw (int,int);
int ves_icall_MonoCustomAttrs_IsDefinedInternal_raw (int,int,int);
int ves_icall_System_Reflection_FieldInfo_internal_from_handle_type_raw (int,int,int);
int ves_icall_System_Reflection_FieldInfo_get_marshal_info_raw (int,int);
int ves_icall_System_Reflection_LoaderAllocatorScout_Destroy (int);
void ves_icall_System_Reflection_RuntimeAssembly_GetInfo_raw (int,int,int,int);
void ves_icall_System_Reflection_Assembly_GetManifestModuleInternal_raw (int,int,int);
void ves_icall_System_Reflection_RuntimeCustomAttributeData_ResolveArgumentsInternal_raw (int,int,int,int,int,int,int);
void ves_icall_RuntimeEventInfo_get_event_info_raw (int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_System_Reflection_EventInfo_internal_from_handle_type_raw (int,int,int);
int ves_icall_RuntimeFieldInfo_ResolveType_raw (int,int);
int ves_icall_RuntimeFieldInfo_GetParentType_raw (int,int,int);
int ves_icall_RuntimeFieldInfo_GetFieldOffset_raw (int,int);
int ves_icall_RuntimeFieldInfo_GetValueInternal_raw (int,int,int);
int ves_icall_RuntimeFieldInfo_GetRawConstantValue_raw (int,int);
int ves_icall_reflection_get_token_raw (int,int);
void ves_icall_get_method_info_raw (int,int,int);
int ves_icall_get_method_attributes (int);
int ves_icall_System_Reflection_MonoMethodInfo_get_parameter_info_raw (int,int,int);
int ves_icall_System_MonoMethodInfo_get_retval_marshal_raw (int,int);
int ves_icall_System_Reflection_RuntimeMethodInfo_GetMethodFromHandleInternalType_native_raw (int,int,int,int);
int ves_icall_RuntimeMethodInfo_get_name_raw (int,int);
int ves_icall_RuntimeMethodInfo_get_base_method_raw (int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_InternalInvoke_raw (int,int,int,int,int);
void ves_icall_RuntimeMethodInfo_GetPInvoke_raw (int,int,int,int,int);
int ves_icall_RuntimeMethodInfo_GetGenericArguments_raw (int,int);
int ves_icall_RuntimeMethodInfo_get_IsGenericMethodDefinition_raw (int,int);
int ves_icall_RuntimeMethodInfo_get_IsGenericMethod_raw (int,int);
void ves_icall_InvokeClassConstructor_raw (int,int);
int ves_icall_InternalInvoke_raw (int,int,int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
void ves_icall_RuntimePropertyInfo_get_property_info_raw (int,int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_System_Reflection_RuntimePropertyInfo_internal_from_handle_type_raw (int,int,int);
void ves_icall_DynamicMethod_create_dynamic_method_raw (int,int,int,int,int);
void ves_icall_AssemblyBuilder_basic_init_raw (int,int);
void ves_icall_AssemblyBuilder_UpdateNativeCustomAttributes_raw (int,int);
void ves_icall_ModuleBuilder_basic_init_raw (int,int);
void ves_icall_ModuleBuilder_set_wrappers_type_raw (int,int,int);
int ves_icall_ModuleBuilder_getToken_raw (int,int,int,int);
void ves_icall_ModuleBuilder_RegisterToken_raw (int,int,int,int);
int ves_icall_TypeBuilder_create_runtime_class_raw (int,int);
int ves_icall_System_Diagnostics_StackFrame_GetFrameInfo (int,int,int,int,int,int,int,int);
void ves_icall_System_Diagnostics_StackTrace_GetTrace (int,int,int,int);
int ves_icall_Mono_RuntimeClassHandle_GetTypeFromClass (int);
void ves_icall_Mono_RuntimeGPtrArrayHandle_GPtrArrayFree (int);
int ves_icall_Mono_SafeStringMarshal_StringToUtf8 (int);
void ves_icall_Mono_SafeStringMarshal_GFree (int);
static void *corlib_icall_funcs [] = {
// token 183,
ves_icall_System_Array_InternalCreate,
// token 191,
ves_icall_System_Array_GetCorElementTypeOfElementTypeInternal,
// token 192,
ves_icall_System_Array_CanChangePrimitive,
// token 193,
ves_icall_System_Array_FastCopy,
// token 194,
ves_icall_System_Array_GetLengthInternal_raw,
// token 195,
ves_icall_System_Array_GetLowerBoundInternal_raw,
// token 196,
ves_icall_System_Array_GetGenericValue_icall,
// token 197,
ves_icall_System_Array_GetValueImpl_raw,
// token 199,
ves_icall_System_Array_SetValueImpl_raw,
// token 200,
ves_icall_System_Array_SetValueRelaxedImpl_raw,
// token 229,
ves_icall_System_Runtime_RuntimeImports_ZeroMemory,
// token 230,
ves_icall_System_Runtime_RuntimeImports_Memmove,
// token 231,
ves_icall_System_Buffer_BulkMoveWithWriteBarrier,
// token 249,
ves_icall_System_Delegate_CreateDelegate_internal_raw,
// token 250,
ves_icall_System_Delegate_GetVirtualMethod_internal_raw,
// token 253,
ves_icall_System_Enum_GetEnumValuesAndNames_raw,
// token 254,
ves_icall_System_Enum_InternalBoxEnum_raw,
// token 255,
ves_icall_System_Enum_InternalGetCorElementType,
// token 256,
ves_icall_System_Enum_InternalGetUnderlyingType_raw,
// token 316,
ves_icall_System_Environment_get_ProcessorCount,
// token 317,
ves_icall_System_Environment_get_TickCount,
// token 320,
ves_icall_System_Environment_FailFast_raw,
// token 347,
ves_icall_System_GC_register_ephemeron_array_raw,
// token 348,
ves_icall_System_GC_get_ephemeron_tombstone_raw,
// token 350,
ves_icall_System_GC_SuppressFinalize_raw,
// token 352,
ves_icall_System_GC_ReRegisterForFinalize_raw,
// token 354,
ves_icall_System_GC_GetGCMemoryInfo,
// token 356,
ves_icall_System_GC_AllocPinnedArray_raw,
// token 361,
ves_icall_System_Object_MemberwiseClone_raw,
// token 369,
ves_icall_System_Math_Ceiling,
// token 370,
ves_icall_System_Math_Cos,
// token 371,
ves_icall_System_Math_Floor,
// token 372,
ves_icall_System_Math_Log10,
// token 373,
ves_icall_System_Math_Pow,
// token 374,
ves_icall_System_Math_Sin,
// token 375,
ves_icall_System_Math_Sqrt,
// token 376,
ves_icall_System_Math_Tan,
// token 377,
ves_icall_System_Math_ModF,
// token 448,
ves_icall_RuntimeMethodHandle_ReboxFromNullable_raw,
// token 449,
ves_icall_RuntimeMethodHandle_ReboxToNullable_raw,
// token 500,
ves_icall_RuntimeType_GetCorrespondingInflatedMethod_raw,
// token 505,
ves_icall_RuntimeType_make_array_type_raw,
// token 508,
ves_icall_RuntimeType_make_byref_type_raw,
// token 510,
ves_icall_RuntimeType_make_pointer_type_raw,
// token 515,
ves_icall_RuntimeType_MakeGenericType_raw,
// token 516,
ves_icall_RuntimeType_GetMethodsByName_native_raw,
// token 518,
ves_icall_RuntimeType_GetPropertiesByName_native_raw,
// token 519,
ves_icall_RuntimeType_GetConstructors_native_raw,
// token 523,
ves_icall_System_RuntimeType_CreateInstanceInternal_raw,
// token 524,
ves_icall_System_RuntimeType_AllocateValueType_raw,
// token 526,
ves_icall_RuntimeType_GetDeclaringMethod_raw,
// token 528,
ves_icall_System_RuntimeType_getFullName_raw,
// token 529,
ves_icall_RuntimeType_GetGenericArgumentsInternal_raw,
// token 532,
ves_icall_RuntimeType_GetGenericParameterPosition,
// token 533,
ves_icall_RuntimeType_GetEvents_native_raw,
// token 534,
ves_icall_RuntimeType_GetFields_native_raw,
// token 537,
ves_icall_RuntimeType_GetInterfaces_raw,
// token 539,
ves_icall_RuntimeType_GetDeclaringType_raw,
// token 541,
ves_icall_RuntimeType_GetName_raw,
// token 543,
ves_icall_RuntimeType_GetNamespace_raw,
// token 552,
ves_icall_RuntimeType_FunctionPointerReturnAndParameterTypes_raw,
// token 604,
ves_icall_RuntimeTypeHandle_GetAttributes,
// token 606,
ves_icall_RuntimeTypeHandle_GetMetadataToken_raw,
// token 608,
ves_icall_RuntimeTypeHandle_GetGenericTypeDefinition_impl_raw,
// token 618,
ves_icall_RuntimeTypeHandle_GetCorElementType,
// token 619,
ves_icall_RuntimeTypeHandle_HasInstantiation,
// token 620,
ves_icall_RuntimeTypeHandle_IsInstanceOfType_raw,
// token 622,
ves_icall_RuntimeTypeHandle_HasReferences_raw,
// token 628,
ves_icall_RuntimeTypeHandle_GetArrayRank_raw,
// token 629,
ves_icall_RuntimeTypeHandle_GetAssembly_raw,
// token 630,
ves_icall_RuntimeTypeHandle_GetElementType_raw,
// token 631,
ves_icall_RuntimeTypeHandle_GetModule_raw,
// token 632,
ves_icall_RuntimeTypeHandle_GetBaseType_raw,
// token 640,
ves_icall_RuntimeTypeHandle_type_is_assignable_from_raw,
// token 641,
ves_icall_RuntimeTypeHandle_IsGenericTypeDefinition,
// token 642,
ves_icall_RuntimeTypeHandle_GetGenericParameterInfo_raw,
// token 646,
ves_icall_RuntimeTypeHandle_is_subclass_of_raw,
// token 647,
ves_icall_RuntimeTypeHandle_IsByRefLike_raw,
// token 649,
ves_icall_System_RuntimeTypeHandle_internal_from_name_raw,
// token 651,
ves_icall_System_String_FastAllocateString_raw,
// token 778,
ves_icall_System_Type_internal_from_handle_raw,
// token 922,
ves_icall_System_ValueType_InternalGetHashCode_raw,
// token 923,
ves_icall_System_ValueType_Equals_raw,
// token 4302,
ves_icall_System_Threading_Interlocked_CompareExchange_Int,
// token 4303,
ves_icall_System_Threading_Interlocked_CompareExchange_Object,
// token 4305,
ves_icall_System_Threading_Interlocked_Decrement_Int,
// token 4306,
ves_icall_System_Threading_Interlocked_Increment_Int,
// token 4307,
ves_icall_System_Threading_Interlocked_Exchange_Int,
// token 4308,
ves_icall_System_Threading_Interlocked_Exchange_Object,
// token 4310,
ves_icall_System_Threading_Interlocked_CompareExchange_Long,
// token 4312,
ves_icall_System_Threading_Interlocked_Exchange_Long,
// token 4314,
ves_icall_System_Threading_Interlocked_Add_Int,
// token 4319,
ves_icall_System_Threading_Monitor_Monitor_Enter_raw,
// token 4321,
mono_monitor_exit_icall_raw,
// token 4325,
ves_icall_System_Threading_Monitor_Monitor_pulse_all_raw,
// token 4327,
ves_icall_System_Threading_Monitor_Monitor_wait_raw,
// token 4329,
ves_icall_System_Threading_Monitor_Monitor_try_enter_with_atomic_var_raw,
// token 4380,
ves_icall_System_Threading_Thread_InitInternal_raw,
// token 4381,
ves_icall_System_Threading_Thread_GetCurrentThread,
// token 4383,
ves_icall_System_Threading_InternalThread_Thread_free_internal_raw,
// token 4384,
ves_icall_System_Threading_Thread_GetState_raw,
// token 4385,
ves_icall_System_Threading_Thread_SetState_raw,
// token 4386,
ves_icall_System_Threading_Thread_ClrState_raw,
// token 4387,
ves_icall_System_Threading_Thread_SetName_icall_raw,
// token 4389,
ves_icall_System_Threading_Thread_YieldInternal,
// token 4391,
ves_icall_System_Threading_Thread_SetPriority_raw,
// token 4877,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_PrepareForAssemblyLoadContextRelease_raw,
// token 4880,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_GetLoadContextForAssembly_raw,
// token 4882,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFile_raw,
// token 4883,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalInitializeNativeALC_raw,
// token 4884,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFromStream_raw,
// token 5053,
ves_icall_System_GCHandle_InternalAlloc_raw,
// token 5054,
ves_icall_System_GCHandle_InternalFree_raw,
// token 5055,
ves_icall_System_GCHandle_InternalGet_raw,
// token 5071,
ves_icall_System_Runtime_InteropServices_Marshal_GetLastPInvokeError,
// token 5072,
ves_icall_System_Runtime_InteropServices_Marshal_SetLastPInvokeError,
// token 5073,
ves_icall_System_Runtime_InteropServices_Marshal_StructureToPtr_raw,
// token 5109,
ves_icall_System_Runtime_InteropServices_NativeLibrary_LoadByName_raw,
// token 5170,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalGetHashCode_raw,
// token 5172,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalTryGetHashCode_raw,
// token 5180,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetUninitializedObjectInternal_raw,
// token 5181,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray_raw,
// token 5182,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetSpanDataFrom_raw,
// token 5183,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_SufficientExecutionStack,
// token 5319,
ves_icall_System_Reflection_Assembly_GetEntryAssembly_raw,
// token 5321,
ves_icall_System_Reflection_Assembly_InternalLoad_raw,
// token 5341,
ves_icall_System_Reflection_AssemblyName_GetNativeName,
// token 5355,
ves_icall_MonoCustomAttrs_GetCustomAttributesInternal_raw,
// token 5361,
ves_icall_MonoCustomAttrs_GetCustomAttributesDataInternal_raw,
// token 5368,
ves_icall_MonoCustomAttrs_IsDefinedInternal_raw,
// token 5379,
ves_icall_System_Reflection_FieldInfo_internal_from_handle_type_raw,
// token 5382,
ves_icall_System_Reflection_FieldInfo_get_marshal_info_raw,
// token 5398,
ves_icall_System_Reflection_LoaderAllocatorScout_Destroy,
// token 5470,
ves_icall_System_Reflection_RuntimeAssembly_GetInfo_raw,
// token 5472,
ves_icall_System_Reflection_Assembly_GetManifestModuleInternal_raw,
// token 5478,
ves_icall_System_Reflection_RuntimeCustomAttributeData_ResolveArgumentsInternal_raw,
// token 5486,
ves_icall_RuntimeEventInfo_get_event_info_raw,
// token 5504,
ves_icall_reflection_get_token_raw,
// token 5505,
ves_icall_System_Reflection_EventInfo_internal_from_handle_type_raw,
// token 5513,
ves_icall_RuntimeFieldInfo_ResolveType_raw,
// token 5515,
ves_icall_RuntimeFieldInfo_GetParentType_raw,
// token 5521,
ves_icall_RuntimeFieldInfo_GetFieldOffset_raw,
// token 5522,
ves_icall_RuntimeFieldInfo_GetValueInternal_raw,
// token 5525,
ves_icall_RuntimeFieldInfo_GetRawConstantValue_raw,
// token 5529,
ves_icall_reflection_get_token_raw,
// token 5535,
ves_icall_get_method_info_raw,
// token 5536,
ves_icall_get_method_attributes,
// token 5543,
ves_icall_System_Reflection_MonoMethodInfo_get_parameter_info_raw,
// token 5545,
ves_icall_System_MonoMethodInfo_get_retval_marshal_raw,
// token 5556,
ves_icall_System_Reflection_RuntimeMethodInfo_GetMethodFromHandleInternalType_native_raw,
// token 5559,
ves_icall_RuntimeMethodInfo_get_name_raw,
// token 5560,
ves_icall_RuntimeMethodInfo_get_base_method_raw,
// token 5561,
ves_icall_reflection_get_token_raw,
// token 5571,
ves_icall_InternalInvoke_raw,
// token 5579,
ves_icall_RuntimeMethodInfo_GetPInvoke_raw,
// token 5584,
ves_icall_RuntimeMethodInfo_GetGenericArguments_raw,
// token 5585,
ves_icall_RuntimeMethodInfo_get_IsGenericMethodDefinition_raw,
// token 5586,
ves_icall_RuntimeMethodInfo_get_IsGenericMethod_raw,
// token 5602,
ves_icall_InvokeClassConstructor_raw,
// token 5604,
ves_icall_InternalInvoke_raw,
// token 5616,
ves_icall_reflection_get_token_raw,
// token 5652,
ves_icall_RuntimePropertyInfo_get_property_info_raw,
// token 5674,
ves_icall_reflection_get_token_raw,
// token 5675,
ves_icall_System_Reflection_RuntimePropertyInfo_internal_from_handle_type_raw,
// token 6064,
ves_icall_DynamicMethod_create_dynamic_method_raw,
// token 6117,
ves_icall_AssemblyBuilder_basic_init_raw,
// token 6118,
ves_icall_AssemblyBuilder_UpdateNativeCustomAttributes_raw,
// token 6248,
ves_icall_ModuleBuilder_basic_init_raw,
// token 6249,
ves_icall_ModuleBuilder_set_wrappers_type_raw,
// token 6253,
ves_icall_ModuleBuilder_getToken_raw,
// token 6256,
ves_icall_ModuleBuilder_RegisterToken_raw,
// token 6312,
ves_icall_TypeBuilder_create_runtime_class_raw,
// token 6608,
ves_icall_System_Diagnostics_StackFrame_GetFrameInfo,
// token 6618,
ves_icall_System_Diagnostics_StackTrace_GetTrace,
// token 6913,
ves_icall_Mono_RuntimeClassHandle_GetTypeFromClass,
// token 6934,
ves_icall_Mono_RuntimeGPtrArrayHandle_GPtrArrayFree,
// token 6936,
ves_icall_Mono_SafeStringMarshal_StringToUtf8,
// token 6938,
ves_icall_Mono_SafeStringMarshal_GFree,
};
static uint8_t corlib_icall_flags [] = {
0,
0,
0,
0,
4,
4,
0,
4,
4,
4,
0,
0,
0,
4,
4,
4,
4,
0,
4,
0,
0,
4,
4,
4,
4,
4,
0,
4,
4,
0,
0,
0,
0,
0,
0,
0,
0,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
0,
0,
4,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
4,
0,
0,
0,
0,
0,
0,
0,
0,
0,
4,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
0,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
0,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
0,
0,
0,
0,
0,
};
