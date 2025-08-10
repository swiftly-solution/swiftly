using SwiftlyS2.API.Scripting;

Commands.Register("removemenu", (int playerid, string[] args, int argsCount, bool silent, string prefix) =>
{
    Menus.Unregister("admin_menu");
});