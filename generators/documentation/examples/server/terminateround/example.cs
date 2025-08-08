using SwiftlyS2.API.Scripting;

Commands.Register("ip", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Server.TerminateRound(0.5, RoundEndReason_t.TerroristsPlanted);
});