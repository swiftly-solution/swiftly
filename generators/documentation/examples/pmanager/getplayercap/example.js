commands.Register("maxplayers", (playerId, args, argc, silent, prefix) => {
    console.log(`Maximum players: ${playermanager.GetPlayerCap()}`);
});