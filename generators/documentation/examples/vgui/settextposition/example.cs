using SwiftlyS2.API.Scripting;

Commands.Register("updatetext", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    VGUI.SetTextPosition(3, 0.95, 0.90);
});