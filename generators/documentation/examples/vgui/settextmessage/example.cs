using SwiftlyS2.API.Scripting;

Commands.Register("updatetext", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    VGUI.ShowText(3, "New text!");
});