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
4305,
4306,
4308,
4309,
4310,
4311,
4313,
4315,
4317,
4322,
4324,
4328,
4330,
4332,
4383,
4384,
4386,
4387,
4388,
4389,
4390,
4392,
4394,
4880,
4883,
4885,
4886,
4887,
5059,
5060,
5061,
5077,
5078,
5079,
5115,
5176,
5178,
5186,
5187,
5188,
5189,
5325,
5327,
5347,
5361,
5367,
5374,
5385,
5388,
5404,
5476,
5478,
5484,
5492,
5510,
5511,
5519,
5521,
5527,
5528,
5531,
5535,
5541,
5542,
5549,
5551,
5562,
5565,
5566,
5567,
5577,
5585,
5590,
5591,
5592,
5608,
5610,
5622,
5658,
5680,
5681,
6070,
6123,
6124,
6254,
6255,
6259,
6262,
6318,
6614,
6624,
6919,
6940,
6942,
6944,
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
// token 4305,
ves_icall_System_Threading_Interlocked_CompareExchange_Int,
// token 4306,
ves_icall_System_Threading_Interlocked_CompareExchange_Object,
// token 4308,
ves_icall_System_Threading_Interlocked_Decrement_Int,
// token 4309,
ves_icall_System_Threading_Interlocked_Increment_Int,
// token 4310,
ves_icall_System_Threading_Interlocked_Exchange_Int,
// token 4311,
ves_icall_System_Threading_Interlocked_Exchange_Object,
// token 4313,
ves_icall_System_Threading_Interlocked_CompareExchange_Long,
// token 4315,
ves_icall_System_Threading_Interlocked_Exchange_Long,
// token 4317,
ves_icall_System_Threading_Interlocked_Add_Int,
// token 4322,
ves_icall_System_Threading_Monitor_Monitor_Enter_raw,
// token 4324,
mono_monitor_exit_icall_raw,
// token 4328,
ves_icall_System_Threading_Monitor_Monitor_pulse_all_raw,
// token 4330,
ves_icall_System_Threading_Monitor_Monitor_wait_raw,
// token 4332,
ves_icall_System_Threading_Monitor_Monitor_try_enter_with_atomic_var_raw,
// token 4383,
ves_icall_System_Threading_Thread_InitInternal_raw,
// token 4384,
ves_icall_System_Threading_Thread_GetCurrentThread,
// token 4386,
ves_icall_System_Threading_InternalThread_Thread_free_internal_raw,
// token 4387,
ves_icall_System_Threading_Thread_GetState_raw,
// token 4388,
ves_icall_System_Threading_Thread_SetState_raw,
// token 4389,
ves_icall_System_Threading_Thread_ClrState_raw,
// token 4390,
ves_icall_System_Threading_Thread_SetName_icall_raw,
// token 4392,
ves_icall_System_Threading_Thread_YieldInternal,
// token 4394,
ves_icall_System_Threading_Thread_SetPriority_raw,
// token 4880,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_PrepareForAssemblyLoadContextRelease_raw,
// token 4883,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_GetLoadContextForAssembly_raw,
// token 4885,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFile_raw,
// token 4886,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalInitializeNativeALC_raw,
// token 4887,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFromStream_raw,
// token 5059,
ves_icall_System_GCHandle_InternalAlloc_raw,
// token 5060,
ves_icall_System_GCHandle_InternalFree_raw,
// token 5061,
ves_icall_System_GCHandle_InternalGet_raw,
// token 5077,
ves_icall_System_Runtime_InteropServices_Marshal_GetLastPInvokeError,
// token 5078,
ves_icall_System_Runtime_InteropServices_Marshal_SetLastPInvokeError,
// token 5079,
ves_icall_System_Runtime_InteropServices_Marshal_StructureToPtr_raw,
// token 5115,
ves_icall_System_Runtime_InteropServices_NativeLibrary_LoadByName_raw,
// token 5176,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalGetHashCode_raw,
// token 5178,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalTryGetHashCode_raw,
// token 5186,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetUninitializedObjectInternal_raw,
// token 5187,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray_raw,
// token 5188,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetSpanDataFrom_raw,
// token 5189,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_SufficientExecutionStack,
// token 5325,
ves_icall_System_Reflection_Assembly_GetEntryAssembly_raw,
// token 5327,
ves_icall_System_Reflection_Assembly_InternalLoad_raw,
// token 5347,
ves_icall_System_Reflection_AssemblyName_GetNativeName,
// token 5361,
ves_icall_MonoCustomAttrs_GetCustomAttributesInternal_raw,
// token 5367,
ves_icall_MonoCustomAttrs_GetCustomAttributesDataInternal_raw,
// token 5374,
ves_icall_MonoCustomAttrs_IsDefinedInternal_raw,
// token 5385,
ves_icall_System_Reflection_FieldInfo_internal_from_handle_type_raw,
// token 5388,
ves_icall_System_Reflection_FieldInfo_get_marshal_info_raw,
// token 5404,
ves_icall_System_Reflection_LoaderAllocatorScout_Destroy,
// token 5476,
ves_icall_System_Reflection_RuntimeAssembly_GetInfo_raw,
// token 5478,
ves_icall_System_Reflection_Assembly_GetManifestModuleInternal_raw,
// token 5484,
ves_icall_System_Reflection_RuntimeCustomAttributeData_ResolveArgumentsInternal_raw,
// token 5492,
ves_icall_RuntimeEventInfo_get_event_info_raw,
// token 5510,
ves_icall_reflection_get_token_raw,
// token 5511,
ves_icall_System_Reflection_EventInfo_internal_from_handle_type_raw,
// token 5519,
ves_icall_RuntimeFieldInfo_ResolveType_raw,
// token 5521,
ves_icall_RuntimeFieldInfo_GetParentType_raw,
// token 5527,
ves_icall_RuntimeFieldInfo_GetFieldOffset_raw,
// token 5528,
ves_icall_RuntimeFieldInfo_GetValueInternal_raw,
// token 5531,
ves_icall_RuntimeFieldInfo_GetRawConstantValue_raw,
// token 5535,
ves_icall_reflection_get_token_raw,
// token 5541,
ves_icall_get_method_info_raw,
// token 5542,
ves_icall_get_method_attributes,
// token 5549,
ves_icall_System_Reflection_MonoMethodInfo_get_parameter_info_raw,
// token 5551,
ves_icall_System_MonoMethodInfo_get_retval_marshal_raw,
// token 5562,
ves_icall_System_Reflection_RuntimeMethodInfo_GetMethodFromHandleInternalType_native_raw,
// token 5565,
ves_icall_RuntimeMethodInfo_get_name_raw,
// token 5566,
ves_icall_RuntimeMethodInfo_get_base_method_raw,
// token 5567,
ves_icall_reflection_get_token_raw,
// token 5577,
ves_icall_InternalInvoke_raw,
// token 5585,
ves_icall_RuntimeMethodInfo_GetPInvoke_raw,
// token 5590,
ves_icall_RuntimeMethodInfo_GetGenericArguments_raw,
// token 5591,
ves_icall_RuntimeMethodInfo_get_IsGenericMethodDefinition_raw,
// token 5592,
ves_icall_RuntimeMethodInfo_get_IsGenericMethod_raw,
// token 5608,
ves_icall_InvokeClassConstructor_raw,
// token 5610,
ves_icall_InternalInvoke_raw,
// token 5622,
ves_icall_reflection_get_token_raw,
// token 5658,
ves_icall_RuntimePropertyInfo_get_property_info_raw,
// token 5680,
ves_icall_reflection_get_token_raw,
// token 5681,
ves_icall_System_Reflection_RuntimePropertyInfo_internal_from_handle_type_raw,
// token 6070,
ves_icall_DynamicMethod_create_dynamic_method_raw,
// token 6123,
ves_icall_AssemblyBuilder_basic_init_raw,
// token 6124,
ves_icall_AssemblyBuilder_UpdateNativeCustomAttributes_raw,
// token 6254,
ves_icall_ModuleBuilder_basic_init_raw,
// token 6255,
ves_icall_ModuleBuilder_set_wrappers_type_raw,
// token 6259,
ves_icall_ModuleBuilder_getToken_raw,
// token 6262,
ves_icall_ModuleBuilder_RegisterToken_raw,
// token 6318,
ves_icall_TypeBuilder_create_runtime_class_raw,
// token 6614,
ves_icall_System_Diagnostics_StackFrame_GetFrameInfo,
// token 6624,
ves_icall_System_Diagnostics_StackTrace_GetTrace,
// token 6919,
ves_icall_Mono_RuntimeClassHandle_GetTypeFromClass,
// token 6940,
ves_icall_Mono_RuntimeGPtrArrayHandle_GPtrArrayFree,
// token 6942,
ves_icall_Mono_SafeStringMarshal_StringToUtf8,
// token 6944,
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
