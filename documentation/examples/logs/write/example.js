AddEventHandler("OnPlayerConnectFull", (event) => {
    let playerid = event.GetInt("userid")
    let player = GetPlayer(playerid)
    if (!player || !player.IsValid()) return;

    if (!player.CBasePlayerController().IsValid()) return;
    logger.Write(LogType_t.Common, `The player: ${player.CBasePlayerController().PlayerName} joined the server!`)
})