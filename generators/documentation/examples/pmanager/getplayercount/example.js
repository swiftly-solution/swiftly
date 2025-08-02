commands.Register("players", (playerId, args, argc, silent, prefix) => {
    console.log(`There are: ${playermanager.GetPlayerCount()} online!`);
});