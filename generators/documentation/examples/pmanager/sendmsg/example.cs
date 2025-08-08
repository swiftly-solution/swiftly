using SwiftlyS2.API.Scripting;

Commands.Register("message", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    PlayerManager.SendMsg(MessageType.Chat, "Hello there!");
})