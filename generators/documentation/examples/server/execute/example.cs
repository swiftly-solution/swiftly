using SwiftlyS2.API.Scripting;

Commands.Register("command", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Server.Execute("sv_cheats 1");
});