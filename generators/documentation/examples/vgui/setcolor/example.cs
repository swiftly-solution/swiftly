using SwiftlyS2.API.Scripting;
using SwiftlyS2.API.SDK;

Commands.Register("updatecolor", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    VGUI.SetColor(3, new CoreClasses.Color(0, 186, 105, 255));
});