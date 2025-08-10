using SwiftlyS2.API.Scripting;

Commands.Register("menu", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Menus.Register("menu", "Admin Panel", "344CEB", new string[][]
    {
        new[] { "Kick Player", "sw_kick #1" },
        new[] { "Mute Player", "sw_mute #1" },
        new[] { "Ban Player",  "sw_ban #1" }
    }, "screen"); // screen or center
});