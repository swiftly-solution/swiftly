using SwiftlyS2.API.Scripting;

Commands.Register("configfetch", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    var value = Configuration.Fetch<bool>("configuration.test2")
    if (value)
    {
        Console.WriteLine($"Configuration value: {value}");
    }
    else
    {
        Console.WriteLine("Configuration key not found.");
    }
});