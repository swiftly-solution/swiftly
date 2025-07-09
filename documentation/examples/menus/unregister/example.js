commands.Register("removemenu", (playerId, args, argc, silent, prefix) => {
    menus.Unregister("admin_menu")
});