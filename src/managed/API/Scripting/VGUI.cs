using SwiftlyS2.Internal_API;
using static SwiftlyS2.API.SDK.CS2.CoreClasses;

namespace SwiftlyS2.API.Scripting
{
    public class VGUI
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("VGUI", "VGUI", CallKind.ClassFunction);
        }
        public static void RemoveText(long textID)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("VGUI", "RemoveText", Internal_API.CallKind.ClassFunction, _ctx, textID);
        }
        public static void SetColor(long textID, Color color)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("VGUI", "SetColor", Internal_API.CallKind.ClassFunction, _ctx, textID, color);
        }
        public static void SetTextMessage(long textID, string message)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("VGUI", "SetTextMessage", Internal_API.CallKind.ClassFunction, _ctx, textID, message);
        }
        public static void SetTextPosition(long textID, float posX, float posY)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("VGUI", "SetTextPosition", Internal_API.CallKind.ClassFunction, _ctx, textID, posX, posY);
        }
        public static long ShowText(int playerid, Color color, string text, float posX, float posY, string font_name, bool? background)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<long>("VGUI", "ShowText", Internal_API.CallKind.ClassFunction, _ctx, playerid, color, text, posX, posY, font_name, background);
        }
    }
}