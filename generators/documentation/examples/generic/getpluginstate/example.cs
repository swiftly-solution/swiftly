using SwiftlyS2.API.Scripting;

Commands.Register("getpluginstate", (int playerid, int count, bool silent, string arguments[], string prefix) => {
    Console.WriteLine(Generic.GetPluginState("admins"));
});