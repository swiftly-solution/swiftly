using SwiftlyS2.API.Scripting;

Commands.Register("read", (int playerid, string[] args, int argsCount, bool silent, string prefix) =>
{
    var content = Files.Read("addons/swiftly/configs/settings.json");
    if(content)
    {
        Console.WriteLine($"File contents: {content}");;
    }
    else
    {
        Console.WriteLine("Failed to read file");
    }
});
