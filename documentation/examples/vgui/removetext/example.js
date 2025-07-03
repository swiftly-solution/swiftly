commands.Register("removetext", (playerid, args, argc, silent, prefix) => {
    let textId = vgui.ShowText(playerid, Color(255, 255, 255, 255), "Temp Message", 0.5, 0.5, "Arial")
    vgui.RemoveText(textId)
});