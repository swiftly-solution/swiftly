commands.register("decompress", (playerId, args, argc, silent, prefix) => {
    if (files.Decompress("update.zip", "new_version/")) {
        console.log("Decompression succeeded");
    } else {
        console.log("Decompression failed");
    }
});