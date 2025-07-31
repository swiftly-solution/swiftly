using Microsoft.Extensions.DependencyModel;
using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public struct HookHandler
    {
        public string HookId;
    }

    public class Hooks
    {
        private static IntPtr _ctx = IntPtr.Zero;

        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Hooks", "Hooks", CallKind.ClassFunction);
        }

        public static HookHandler AddHookEntityOutput(string class_name, string output)
        {
            InitializeContext();
            HookHandler hookHandler = new();
            hookHandler.HookId = Invoker.CallNative<string>("Hooks", "AddEntityOutputHook", Internal_API.CallKind.ClassFunction, _ctx, class_name, output) ?? "";
            return hookHandler;
        }

        public static HookHandler AddHook(Memory mem, string args_list, string return_type)
        {
            InitializeContext();
            HookHandler hookHandler = new();
            hookHandler.HookId = Invoker.CallNative<string>("Hooks", "Add", Internal_API.CallKind.ClassFunction, _ctx, mem, args_list, return_type) ?? "";
            return hookHandler;
        }

        public static HookHandler AddVHook(string library, string vtable_name, string offset, string args_list, string return_type)
        {
            InitializeContext();
            HookHandler hookHandler = new();
            hookHandler.HookId = Invoker.CallNative<string>("Hooks", "AddVirtual", Internal_API.CallKind.ClassFunction, _ctx, library, vtable_name, offset, args_list, return_type) ?? "";
            return hookHandler;
        }

        public static EventHandler AddPreHookListener(HookHandler handle, Func<Events.Event, EventResult?> cb)
        {
            return Events.AddEventHandler($"hook:Pre:{handle.HookId}", cb);
        }
        
        public static EventHandler AddPostHookListener(HookHandler handle, Func<Events.Event, EventResult?> cb)
        {
            return Events.AddEventHandler($"hook:Post:{handle.HookId}", cb);
        }

        public static void RemoveHookListener(EventHandler ev)
        {
            Events.RemoveEventHandler(ev);
        }

        public static void CallHook(HookHandler hookHandler, params object[] args)
        {
            InitializeContext();
            Invoker.CallNative("Hooks", "Call", Internal_API.CallKind.ClassFunction, _ctx, hookHandler.HookId, (object)args);
        }

        public static T? CallHook<T>(HookHandler hookHandler, params object[] args)
        {
            InitializeContext();
            return Invoker.CallNative<T>("Hooks", "Call", Internal_API.CallKind.ClassFunction, _ctx, hookHandler.HookId, (object)args);
        }
    }
}