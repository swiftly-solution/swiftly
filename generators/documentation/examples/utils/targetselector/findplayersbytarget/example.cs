using SwiftlyS2.API.Scripting;

Commands.Register("getct", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    var players = Generic.FindPlayersByTarget("@ct", true);
    Console.WriteLine($"There are {players.Count} in CT.")
});