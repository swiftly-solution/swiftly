commands.Register("tickcount", (playerId, args, argc, silent, prefix) => {
    console.log(`Tick count: ${server.GetTickCount()}`);
});