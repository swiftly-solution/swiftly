using SwiftlyS2.API.Scripting;

Commands.Register("tempmenu", (int playerid, string[] args, int argsCount, bool silent, string prefix) =>
{
    string menuName = $"temp_menu_{playerid}";

    Menus.RegisterTemporary(menuName, "Admin Panel", "344CEB", new string[][]
    {
        new[] { "Kick Player", "sw_kick #1" },
        new[] { "Mute Player", "sw_mute #1" },
        new[] { "Ban Player",  "sw_ban #1" }
    }, "screen");
});