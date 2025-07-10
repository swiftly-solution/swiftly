commands.Register("command", (playerId, args, argc, silent, prefix) => {
    server.Execute("sv_cheats 1");
});