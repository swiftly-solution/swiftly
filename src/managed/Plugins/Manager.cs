namespace SwiftlyS2.Plugins
{
    public class Manager
    {
        private readonly Dictionary<IntPtr, Context> _pluginList = [];

        public void CreatePlugin(IntPtr context, string path)
        {
            _pluginList[context] = new Context(context, path);
        }

        public void StartPlugin(IntPtr context)
        {
            _pluginList[context].Load();
            _pluginList[context].Start();
        }

        public void StopPlugin(IntPtr context)
        {
            if (_pluginList[context] == null) return;

            _pluginList[context].Unload();
        }

        public void DeletePlugin(IntPtr context)
        {
            _pluginList.Remove(context);
        }

        public UInt64 GetPluginMemoryUsage(IntPtr context)
        {
            if(context == IntPtr.Zero) return 0;
            if (!_pluginList.ContainsKey(context)) return 0;

            Context ctx = _pluginList[context];
            return (UInt64)ctx.Plugin!.GetMemoryUsage();
        }
    }
}
