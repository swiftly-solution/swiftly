using SwiftlyS2.API.Scripting;

Commands.Register("fetchdirs", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    var dirs = Files.FetchDirectories("addons/swiftly/plugins");
    for(var i = 0; i < dirs.Length; i++)
    {
        Console.WriteLine($"Found plugin: {dirs[i]}");
    }
});