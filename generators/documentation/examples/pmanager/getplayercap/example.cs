using SwiftlyS2.API.Scripting;

Commands.Register("maxplayers", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Console.WriteLine($"Maximum players: {PlayerManager.GetPlayerCap()}");
})