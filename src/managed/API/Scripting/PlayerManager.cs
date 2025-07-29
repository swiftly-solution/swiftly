using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class PlayerManager
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("PlayerManager", "PlayerManager", CallKind.ClassFunction);
        }
        public static int GetPlayerCap()
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<int>("PlayerManager", "GetPlayerCap", Internal_API.CallKind.ClassFunction, _ctx);
        }
        public static int GetPlayerCount()
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<int>("PlayerManager", "GetPlayerCount", Internal_API.CallKind.ClassFunction, _ctx);
        }
        public static void SendMsg(MessageType msgType, string text)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("PlayerManager", "SendMsg", Internal_API.CallKind.ClassFunction, _ctx, msgType, text);
        }
    }
}