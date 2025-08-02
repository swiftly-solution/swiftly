commands.Register("maxplayers", (playerId, args, argc, silent, prefix) => {
    console.log(`Max players: ${server.GetMaxPlayers()}`);
});