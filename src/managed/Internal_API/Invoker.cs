using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Security;
using SwiftlyS2.API;

namespace SwiftlyS2.Internal_API
{
    public static class Invoker
    {
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void InvokeNative(IntPtr ptr);

        public static InvokeNative? MyInvokeNative = null;

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void ClassDataFinalizer(IntPtr context, IntPtr ptr);

        public static ClassDataFinalizer? MyClassDataFinalizer = null;

        [SecurityCritical]
        public static T? CallNative<T>(string ns, string func, CallKind call, params object[] args)
        {
            StackTrace trace = new(true);
            StackFrame? callTrace = trace.GetFrame(2);

            CallContext.GlobalScriptContext.Reset();
            CallContext.GlobalScriptContext.PushArgument(Plugin.PluginContext);
            foreach(object arg in args)
            {
                CallContext.GlobalScriptContext.PushArgument(arg);
            }
            CallContext.GlobalScriptContext.SetCallKind(call);
            CallContext.GlobalScriptContext.SetFunction(ns, func);
            if(callTrace != null)
            {
                CallContext.GlobalScriptContext.SetDebugInfo($"{callTrace.GetFileName()}:{callTrace.GetFileLineNumber()}:{callTrace.GetFileColumnNumber()}");
            }
            else
            {
                CallContext.GlobalScriptContext.SetDebugInfo($"No debug symbols available. (PDB file with DLL)");
            }
            CallContext.GlobalScriptContext.InvokeFunction();
            return CallContext.GlobalScriptContext.GetReturn<T>();
        }

        [SecurityCritical]
        public static void CallNative(string ns, string func, CallKind call, params object[] args)
        {
            StackTrace trace = new(true);
            StackFrame? callTrace = trace.GetFrame(2);

            CallContext.GlobalScriptContext.Reset();
            CallContext.GlobalScriptContext.PushArgument(Plugin.PluginContext);
            foreach (object arg in args)
            {
                CallContext.GlobalScriptContext.PushArgument(arg);
            }
            CallContext.GlobalScriptContext.SetCallKind(call);
            CallContext.GlobalScriptContext.SetFunction(ns, func);
            if (callTrace != null)
            {
                CallContext.GlobalScriptContext.SetDebugInfo($"{callTrace.GetFileName()}:{callTrace.GetFileLineNumber()}:{callTrace.GetFileColumnNumber()}");
            }
            else
            {
                CallContext.GlobalScriptContext.SetDebugInfo($"No debug symbols available. (PDB file with DLL)");
            }
            CallContext.GlobalScriptContext.InvokeFunction();
        }

        public static void FinalizeClassdata(IntPtr item)
        {
            if(MyClassDataFinalizer != null)
            {
                MyClassDataFinalizer(Plugin.PluginContext, item);
            }
        }
    }
}
