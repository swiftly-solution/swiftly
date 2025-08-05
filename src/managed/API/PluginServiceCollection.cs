using Microsoft.Extensions.DependencyInjection;

namespace SwiftlyS2.API
{
    public interface IPluginServiceCollection<T> where T : Plugin
    {
        public void ConfigureServiceCollection(IServiceCollection services);
    }
}
