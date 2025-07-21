using McMaster.NETCore.Plugins;
using Microsoft.Extensions.DependencyInjection;
using SwiftlyS2.API;

namespace SwiftlyS2.Plugins
{
    class Context
    {
        private IntPtr m_ctx { get; set; }
        private string m_path { get; set; }

        public API.Plugin? Plugin { get; private set; }

        private PluginLoader Loader { get; set; }

        private ServiceProvider? m_serviceProvider { get; set; }

        private IServiceScope? ServScope { get; set; }

        public Context(IntPtr ctx, string path)
        {
            m_path = path;
            m_ctx = ctx;

            Loader = PluginLoader.CreateFromAssemblyFile(m_path, new[] { typeof(API.Plugin) }, (config) =>
            {
                config.IsUnloadable = true;
                config.PreferSharedTypes = true;
            });
        }

        public void Load()
        {
            using (Loader.EnterContextualReflection())
            {
                var asm = Loader.LoadDefaultAssembly();

                Type? type = asm.GetExportedTypes().FirstOrDefault((t) => typeof(API.Plugin).IsAssignableFrom(t));

                if (type == null)
                {
                    throw new Exception("Invalid SwiftlyS2 .NET Binary. You need to create a class which extends Plugin");
                }

                var servCollection = new ServiceCollection();

                servCollection.Scan((scan) => scan.FromAssemblies(asm).AddClasses((c) => c.AssignableTo<API.Plugin>()).AsSelf().WithSingletonLifetime());

                m_serviceProvider = servCollection.BuildServiceProvider();

                ServScope = m_serviceProvider.CreateScope();

                if (ServScope.ServiceProvider.GetRequiredService(type) is not API.Plugin plugin)
                {
                    throw new Exception("Couldn't initialize plugin instance.");
                }

                Plugin ??= plugin;
                Plugin.Initialize(m_ctx);
            }
        }

        public void Start()
        {
            if (Plugin == null) return;

            Plugin.Load();
        }

        public void Unload()
        {
            if (Plugin == null) return;
            if (ServScope == null) return;

            Plugin.Unload();
            Plugin.Dispose();

            ServScope.Dispose();
        }

        public IntPtr GetContext() => m_ctx;

        public string GetPath() => m_path;
    }
}
