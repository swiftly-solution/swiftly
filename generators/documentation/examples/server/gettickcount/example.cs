using SwiftlyS2.API.Scripting;

Commands.Register("tickcount", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Console.WriteLine($"Tick count: {Server.GetTickCount()}");
});