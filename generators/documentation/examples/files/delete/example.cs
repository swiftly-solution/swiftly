using SwiftlyS2.API.Scripting;

Commands.Register("delete", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Files.Delete("addons/swiftly/logs/log_1.log");
    Console.WriteLine("File deleted");
});