using SwiftlyS2.API.Scripting;
using SwiftlyS2.API.SDK;


Events.AddEventHandler("OnPlayerConnectFull", (Events.Event @e) => {
    var playerid = @e.GetInt("userid");
    var player = Generic.GetPlayer(playerid);
    if(!player || !player.IsValid()) return EventResult.Continue;

    if(!player.CBasePlayerController().IsValid()) return EventResult.Continue;
    Logger.Write(LogType_t.Common, $"The player: {player.CBasePlayerController().PlayerName} joined the server!");
    return EventResult.Continue;
})