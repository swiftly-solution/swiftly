using SwiftlyS2.API.Scripting;

Commands.Register("fetchfiles", (int playerid, string[] args, int argsCount, bool silent, string prefix) =>
{
    var filesList = Files.FetchFileNames("addons/swiftly/configs");
    Console.WriteLine("All configs: " + string.Join(", ", filesList));
});
