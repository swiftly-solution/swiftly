namespace SwiftlyS2.API
{
    public interface IPlugin: IDisposable
    {
        void Load();

        void Unload();

        void Initialize(IntPtr ctx);

        long GetMemoryUsage();
    }
}
