namespace SwiftlyS2.API
{
    public abstract class Plugin : IPlugin
    {

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
            GlobalState.PluginContext = ctx;
            Console.SetOut(new Scripting.ConsoleWriter(Console.Out));
        }

        public long GetMemoryUsage()
        {
            return GC.GetAllocatedBytesForCurrentThread();
        }
    }
}
