using SwiftlyS2.API.Scripting;

Commands.Register("configfetchsize", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    var size = Configuration.FetchArraySize("configuration.test3")
    if(size > 0) {
        Console.WriteLine($"Array size: {size}");
    } else {
        Console.WriteLine("Configuration key is not an array or does not exist.");
    }
})