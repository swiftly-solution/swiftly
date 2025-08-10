using static SwiftlyS2.API.Scripting.Events;
using System.Reflection;
using System.Linq.Expressions;
using SwiftlyS2.Internal_API;
using SwiftlyS2.API.Scripting;

namespace SwiftlyS2.API
{
    public class Plugin : IPlugin
    {
        public static IntPtr PluginContext { get; set; }

        public void Dispose()
        {
        }

        public virtual void Load()
        {
        }

        public virtual void Unload()
        {
        }

        public void Initialize(IntPtr ctx)
        {
            PluginContext = ctx;
            Cacher.PrepareCache();
            Console.SetOut(new Scripting.ConsoleWriter(Console.Out));
            Events.Listener.StartListening();

            RegisterEventAttribute();
            RegisterCommandAttribute();
            RegisterExportAttribute();
        }

        private void RegisterEventAttribute()
        {
            var methods = this.GetType().GetMethods(BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.Public);
            foreach (var method in methods)
            {
                var attr = method.GetCustomAttribute<AddEventHandlerAttribute>();
                if (attr != null)
                {
                    AddEventHandler(attr.EventName, Delegate.CreateDelegate(GetMethodType(method), this, method));
                }
            }
        }

        private void RegisterCommandAttribute()
        {
            var methods = this.GetType().GetMethods(BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.Public);
            foreach (var method in methods)
            {
                var attr = method.GetCustomAttribute<Commands.RegisterAttribute>();
                if (attr != null)
                {
                    Commands.Register(attr.CommandName, (Action<int, string[], int, bool, string>)Delegate.CreateDelegate(GetMethodType(method), this, method));
                }
            }
        }

        private void RegisterExportAttribute()
        {
            var methods = this.GetType().GetMethods(BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.Public);
            foreach (var method in methods)
            {
                var attr = method.GetCustomAttribute<Exports.RegisterAttribute>();
                if (attr != null)
                {
                    Exports.Register(attr.ExportName, Delegate.CreateDelegate(GetMethodType(method), this, method));
                }
            }
        }

        private static Type GetMethodType(MethodInfo info)
        {
            var args = info.GetParameters();
            Type[] types = new Type[args.Length+1];
            for(int i = 0; i < args.Length; i++)
            {
                types[i] = args[i].ParameterType;
            }
            types[args.Length] = info.ReturnType;

            return Expression.GetDelegateType(types);
        }

        public long GetMemoryUsage()
        {
            return GC.GetAllocatedBytesForCurrentThread();
        }
    }
}
