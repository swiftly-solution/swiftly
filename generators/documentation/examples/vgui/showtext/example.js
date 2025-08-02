commands.Register("showtext", (playerid, args, argc, silent, prefix) => {
    let welcomeId = vgui.ShowText(playerid, Color(0, 255, 0, 255), "Welcome!", 0.5, 0.1, "Verdana", true)
});