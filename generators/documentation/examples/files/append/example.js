commands.register("append", (playerId, args, argc, silent, prefix) => {
    files.Append("test/test.log", "Test!", true);
});