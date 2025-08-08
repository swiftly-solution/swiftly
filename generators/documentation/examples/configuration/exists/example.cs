using SwiftlyS2.API.Scripting;

Commands.Register("configexists", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    if (Configuration.Exists("configuration.test")){
        Console.WriteLine("Configuration key 'test' exists!");
    } else {
        Console.WriteLine("Configuration 'test' does not exist!");
    }
});