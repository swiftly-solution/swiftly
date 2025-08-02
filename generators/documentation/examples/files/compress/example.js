commands.register("compress", (playerId, args, argc, silent, prefix) => {
    if (files.Compress("logs/error.log", "archives/errors.zip")) {
        console.log("Compression succeeded");
    } else {
        console.log("Compression failed");
    }
});