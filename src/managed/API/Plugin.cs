namespace SwiftlyS2.API
{
    public abstract class Plugin : IPlugin
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
            Console.SetOut(new Scripting.ConsoleWriter(Console.Out));
            Events.Listener.StartListening();
        }

        public long GetMemoryUsage()
        {
            return GC.GetAllocatedBytesForCurrentThread();
        }
    }
}
