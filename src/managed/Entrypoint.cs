using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using SwiftlyS2.API;
using SwiftlyS2.Internal_API;
using SwiftlyS2.Plugins;

namespace SwiftlyS2
{
    internal class Entrypoint
    {
        private static Manager? _pluginManager;

        [UnmanagedCallersOnly]
        public static void Start(IntPtr entrypoint, IntPtr finalizer)
        {
            _pluginManager = new Manager();
            Invoker.MyInvokeNative = Marshal.GetDelegateForFunctionPointer<Invoker.InvokeNative>(entrypoint);
            Invoker.MyClassDataFinalizer = Marshal.GetDelegateForFunctionPointer<Invoker.ClassDataFinalizer>(finalizer);
        }

        [UnmanagedCallersOnly]
        [SecurityCritical]
        public static unsafe int LoadFile(IntPtr context, IntPtr path, int length)
        {
            try
            {
                if (context == IntPtr.Zero) return 1;
                if (_pluginManager == null) return 1;

                if (path == IntPtr.Zero) return 1;

                byte[] buffer = new byte[length];
                Marshal.Copy(path, buffer, 0, length);
                string file_path = Encoding.UTF8.GetString(buffer);

                _pluginManager.CreatePlugin(context, file_path);
                _pluginManager.StartPlugin(context);
                return 0;
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                return 1;
            }
        }

        [UnmanagedCallersOnly]
        [SecurityCritical]
        public static unsafe void RemoveFile(IntPtr context)
        {
            try
            {
                if (_pluginManager == null) return;
                if (context == IntPtr.Zero) return;

                _pluginManager.StopPlugin(context);
                _pluginManager.DeletePlugin(context);
            } catch(Exception e) { }
        }

        [UnmanagedCallersOnly]
        public static unsafe void InterpretAsString(IntPtr obj, int type, IntPtr outStr, int len)
        {
            try
            {
                if (len <= 0) return;
                if (outStr == IntPtr.Zero) return;
                if (obj == IntPtr.Zero) return;

                var asString = Interpreter.TryInterpretUnknownPtr(obj, type) ?? "Couldn't retrieve the value";

                byte[] bytes = Encoding.UTF8.GetBytes(asString + "\0");
                int bytesLen = Math.Min(len - 1, bytes.Length);
                
                fixed (byte* src = bytes)
                {
                    Buffer.MemoryCopy(src, (void*)outStr, bytesLen, bytesLen);
                }
            } catch(Exception e) { }
        }

        [UnmanagedCallersOnly]
        public static unsafe IntPtr AllocateContextPointer(int elementSize, int count)
        {
            return CallContext.GlobalScriptContext.AllocatePointer(elementSize, count);
        }

        [UnmanagedCallersOnly]
        public static unsafe ulong GetPluginMemoryUsage(IntPtr context)
        {
            return _pluginManager!.GetPluginMemoryUsage(context);
        }

        [UnmanagedCallersOnly]
        public static unsafe void UpdateGlobalStateCleanupLock(int state)
        {
            CallContext.GlobalScriptContext.SetCleanupLock(state == 1);
        }

        [UnmanagedCallersOnly]
        [SecurityCritical]
        public static unsafe void ExecuteFunction(IntPtr context, IntPtr plugin_ctx)
        {
            CallData* ct = (CallData*)context;
            CallContext ctx = new(ct);

            IntPtr old_ctx = Plugin.PluginContext;
            Plugin.PluginContext = plugin_ctx;

            string functionName = Encoding.UTF8.GetString(new ReadOnlySpan<byte>((void*)ct->func_ptr, ct->func_length));
            FunctionCallers.GetActionCaller(plugin_ctx, functionName)(ctx);

            Plugin.PluginContext = old_ctx;
        }
    }
}
