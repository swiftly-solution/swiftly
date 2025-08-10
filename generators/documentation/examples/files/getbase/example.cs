using SwiftlyS2.API.Scripting;

Commands.Register("getbase", (int playerid, string[] args, int argsCount, bool silent, string prefix) =>
{
    var name = Files.GetBase("cfg/autoexec.cfg");
    Console.WriteLine($"Base filename: {name}");
});
