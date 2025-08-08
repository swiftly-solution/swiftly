using SwiftlyS2.API.Scripting;

Commands.Register("createdir", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    if(Files.CreateDirectory("addons/swiftly/plugins/test"))
    {
        Console.WriteLine("Directory created successfully");
    }
    else
    {
        Console.WriteLine("Failed to create directory");
    }
});