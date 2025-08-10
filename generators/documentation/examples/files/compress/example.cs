using SwiftlyS2.API.Scripting;

Commands.Register("compress", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    if(Files.Compress("logs/error.log", "archives/errors.zip"))
    {
        Console.WriteLine("Compression succeeded");
    }
    else
    {
        Console.WriteLine("Compression failed");
    }
});