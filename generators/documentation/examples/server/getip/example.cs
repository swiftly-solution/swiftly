using SwiftlyS2.API.Scripting;

Commands.Register("ip", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Console.WriteLine($"Server IP: {Server.GetIP()}");
});