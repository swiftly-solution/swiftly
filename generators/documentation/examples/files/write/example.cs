using SwiftlyS2.API.Scripting;

Commands.Register("read", (int playerid, string[] args, int argsCount, bool silent, string prefix) =>
{
    Files.Write("addons/swiftly/important/important.txt", "Important data", true);
    Console.WriteLine("File written");
});
