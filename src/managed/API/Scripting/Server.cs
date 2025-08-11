using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class Server
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Server", "Server", CallKind.ClassFunction);
        }
        public static void ChangeMap(string map, bool workshop)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Server", "ChangeMap", Internal_API.CallKind.CoreClassFunction, _ctx, map, workshop);
        }
        public static void Execute(string command)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Server", "Execute", Internal_API.CallKind.CoreClassFunction, _ctx, command);
        }
        public static float GetCurrentTime()
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<float>("Server", "GetCurrentTime", Internal_API.CallKind.CoreClassFunction, _ctx);
        }
        public static string GetIP()
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<string>("Server", "GetIP", Internal_API.CallKind.CoreClassFunction, _ctx) ?? "";
        }
        public static string GetMap()
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<string>("Server", "GetMap", Internal_API.CallKind.CoreClassFunction, _ctx) ?? "";
        }
        public static int GetMaxPlayers()
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<int>("Server", "GetMaxPlayers", Internal_API.CallKind.CoreClassFunction, _ctx);
        }
        public static int GetTickCount()
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<int>("Server", "GetTickCount", Internal_API.CallKind.CoreClassFunction, _ctx);
        }
        public static bool IsMapValid(string map)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<bool>("Server", "IsMapValid", Internal_API.CallKind.CoreClassFunction, _ctx, map);
        }
        public static void TerminateRound(float delay, RoundEndReason_t reason)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Server", "TerminateRound", Internal_API.CallKind.CoreClassFunction, _ctx, delay, reason);
        }

        public static Memory FindGameSystem(string name)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<Memory>("Server", "GetGameSystem", Internal_API.CallKind.CoreClassFunction, _ctx, name) ?? new();
        }
    }
}