using SwiftlyS2.API.Scripting;

Commands.Register("createdir", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    if(Files.ExistsPath("test.json"))
    {
        Console.WriteLine("Config file present");
    }
    else
    {
        Console.WriteLine("Config file not found");
    }
});