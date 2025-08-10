using SwiftlyS2.API.Scripting;

Commands.Register("testexport", (int playerid, string[] arguments, bool silent, int count, string prefix) => {
    var player = Generic.GetPlayer(playerid);
    if(!player) return EventResult.Continue;

    if(!Exports.Call<bool>("admins", "HasFlags", playerid)){
        return player.SendMsg(MessageType.Chat, "You don't have the right flag for this command!");
    }
});