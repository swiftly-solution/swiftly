using SwiftlyS2.API.Scripting;

Commands.Register("time", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Console.WriteLine($"Current time: {Server.GetCurrentTime()}");
});