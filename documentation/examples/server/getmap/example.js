commands.Register("currentmap", (playerId, args, argc, silent, prefix) => {
    console.log(`Current map is: ${server.GetMap()}`);
});