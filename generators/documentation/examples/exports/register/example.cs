using SwiftlyS2.API.Scripting;

Exports.Register("GetCredits", (int playerid) => {
    var player = Generic.GetPlayer(playerid);
    if(player == null) return 0;
    if(player.IsFakeClient()) return 0;

    return player.GetVar<int>("credits")
})
