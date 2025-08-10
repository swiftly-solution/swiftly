using SwiftlyS2.API.Scripting;

Commands.Register("isdir", (int playerid, string[] args, int argsCount, bool silent, string prefix) =>
{
    if(Files.IsDirectory("test")){
        Console.WriteLine("This is a folder");
    } else {
        Console.WriteLine("Not a folder");
    }
});
