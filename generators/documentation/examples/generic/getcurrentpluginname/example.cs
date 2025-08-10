using SwiftlyS2.API.Scripting;

Commands.Register("pluginname", (int playerid, int count, bool silent, string arguments[], string prefix) => {
    Console.WriteLine(Generic.GetCurrentPluginName());
});