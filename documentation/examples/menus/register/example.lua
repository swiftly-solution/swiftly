commands:Register("menu", function(playerid, args, argsCount, silent, prefix)
    menus:Register("menu", "Admin Panel", "344CEB", {
        { "Kick Player", "sw_kick #1" },
        { "Mute Player", "sw_mute #1" },
        { "Ban Player",  "sw_ban #1" }
    }, "screen") -- screen or center
end)
