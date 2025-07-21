namespace SwiftlyS2.API.Scripting
{
    public class Generic
    {
        public static string GetGameName()
        {
            return Internal_API.Invoker.CallNative<string>("_G", "GetGameName", Internal_API.CallKind.Function) ?? "";
        }

        public static string GetCurrentPluginName()
        {
            return Internal_API.Invoker.CallNative<string>("_G", "GetCurrentPluginName", Internal_API.CallKind.Function) ?? "";
        }

        public static UInt64 GetTime()
        {
            return Internal_API.Invoker.CallNative<UInt64>("_G", "GetTime", Internal_API.CallKind.Function);
        }

        public static bool IsLinux()
        {
            return Internal_API.Invoker.CallNative<bool>("_G", "IsLinux", Internal_API.CallKind.Function);
        }

        public static string CreateTextTable(string[][] value)
        {
            return Internal_API.Invoker.CallNative<string>("_G", "CreateTextTable", Internal_API.CallKind.Function, (object)value) ?? "";
        }

        public static Dictionary<string, string>[] GetPluginsList()
        {
            return Internal_API.Invoker.CallNative<Dictionary<string, string>[]>("_G", "GetPluginsList", Internal_API.CallKind.Function) ?? [];
        }
    }
}
