commands.Register("ip", (playerId, args, argc, silent, prefix) => {
    console.log(`Server IP: ${server.GetIP()}`);
});
