commands.Register("testexport", (playerid, arguments, arguments_count, silent, prefix) => {
    let player = GetPlayer(playerid)
    if (!player || !player.IsValid()) return

    if (!exports["admins"].HasFlags(playerid, "b")) {
        return player.SendMsg(MessageType.Chat, "You don't have the right flag for this command!")
    }
})