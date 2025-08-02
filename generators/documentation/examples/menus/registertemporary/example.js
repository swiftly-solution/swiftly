commands.Register("tempmenu", (playerId, args, argc, silent, prefix) => {
    menus.RegisterTemporary(`temp_menu_${playerId}`, playerId, "Admin Panel", "344CEB",
        [
            ["Kick Player", "sw_kick #1"],
            ["Mute Player", "sw_mute #1"],
            ["Ban Player", "sw_ban #1"]
        ],
        "screen" // or "center"
    );
});