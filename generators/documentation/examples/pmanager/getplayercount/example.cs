using SwiftlyS2.API.Scripting;

Commands.Register("players", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Console.WriteLine($"There are: {PlayerManager.GetPlayerCount()} players online!");
})