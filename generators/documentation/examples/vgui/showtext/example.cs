using SwiftlyS2.API.Scripting;
using SwiftlyS2.API.SDK;

Commands.Register("updatetext", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    var welcomeId = VGUI.ShowText(playerid, new CoreClasses.Color(0, 255, 0, 255), "Welcome!", 0.5, 0.1, "Verdana", true);
});