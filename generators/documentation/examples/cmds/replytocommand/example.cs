using SwiftlyS2.API.Scripting;

Commands.Register("replycmd", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Generic.ReplyToCommand(playerid, "[PREFIX]", "Some reply!");
});