using SwiftlyS2.API.Scripting;

Commands.Register("getgamename", (int playerid, int count, bool silent, string arguments[], string prefix) => {
    Console.WriteLine(Generic.GetGameName());
});