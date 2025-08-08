using SwiftlyS2.API.Scripting;
using SwiftlyS2.API.SDK;

Commands.Register("removetext", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    var textId = VGUI.ShowText(playerid, new CoreClasses.Color(255, 255, 255, 255), "Temp Message", 0.5, 0.5, "Arial");
    VGUI.RemoveText(textId);
});