using SwiftlyS2.API.Scripting;

Commands.Register("configreload", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Configuration.Reload("configuration");
    Console.WriteLine("Configuration reloaded for 'configuration'");
})