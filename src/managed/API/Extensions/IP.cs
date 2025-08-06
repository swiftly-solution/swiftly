using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Extensions
{
    public class IP
    {
        private static IntPtr _ctx = IntPtr.Zero;

        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("IPAPI", "IPAPI", CallKind.ClassFunction);
        }

        public static string GetIsoCode(string ip)
        {
            InitializeContext();
            return Invoker.CallNative<string>("IPAPI", "GetIsoCode", CallKind.ClassFunction, _ctx, ip) ?? "";
        }
        public static string GetContinent(string ip)
        {
            InitializeContext();
            return Invoker.CallNative<string>("IPAPI", "GetContinent", CallKind.ClassFunction, _ctx, ip) ?? "";
        }
        public static string GetCountry(string ip)
        {
            InitializeContext();
            return Invoker.CallNative<string>("IPAPI", "GetCountry", CallKind.ClassFunction, _ctx, ip) ?? "";
        }
        public static string GetRegion(string ip)
        {
            InitializeContext();
            return Invoker.CallNative<string>("IPAPI", "GetRegion", CallKind.ClassFunction, _ctx, ip) ?? "";
        }
        public static string GetCity(string ip)
        {
            InitializeContext();
            return Invoker.CallNative<string>("IPAPI", "GetCity", CallKind.ClassFunction, _ctx, ip) ?? "";
        }
        public static string GetTimezone(string ip)
        {
            InitializeContext();
            return Invoker.CallNative<string>("IPAPI", "GetTimezone", CallKind.ClassFunction, _ctx, ip) ?? "";
        }
        public static float GetLatitude(string ip)
        {
            InitializeContext();
            return Invoker.CallNative<float>("IPAPI", "GetLatitude", CallKind.ClassFunction, _ctx, ip);
        }
        public static float GetLongitude(string ip)
        {
            InitializeContext();
            return Invoker.CallNative<float>("IPAPI", "GetLongitude", CallKind.ClassFunction, _ctx, ip);
        }
        public static string GetASN(string ip)
        {
            InitializeContext();
            return Invoker.CallNative<string>("IPAPI", "GetASN", CallKind.ClassFunction, _ctx, ip) ?? "";
        }
    }
}
