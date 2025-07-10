commands.Register("time", (playerId, args, argc, silent, prefix) => {
    console.log(`Current time: ${server.GetCurrentTime()}`);
});