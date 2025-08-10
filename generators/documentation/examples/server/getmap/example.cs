using SwiftlyS2.API.Scripting;

Commands.Register("currentmap", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Console.WriteLine($"Current map is: {Server.GetMap()}");
});