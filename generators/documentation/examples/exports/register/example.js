exp("GetCredits", (playerid) => {
    let player = GetPlayer(playerid)
    if (!player) return 0
    if (player.IsFakeClient()) return 0
    return player.GetVar("credits")
})