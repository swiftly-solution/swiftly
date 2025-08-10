using SwiftlyS2.API.Scripting;

Commands.Register("getpath", (int playerid, int count, bool silent, string arguments[], string prefix) => {
    Console.WriteLine(Generic.GetPluginPath("admins"));
});