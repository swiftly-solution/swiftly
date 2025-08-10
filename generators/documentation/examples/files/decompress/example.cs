using SwiftlyS2.API.Scripting;

Commands.Register("creadecompresstedir", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    if(Files.Decompress("update.zip", "new_version/"))
    {
        Console.WriteLine("Decompression succeeded");
    }
    else
    {
        Console.WriteLine("Decompression failed");
    }
});