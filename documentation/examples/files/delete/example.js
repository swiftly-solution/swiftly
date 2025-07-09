commands.register("delete", (playerId, args, argc, silent, prefix) => {
    files.Delete("addons/swiftly/logs/log_1.log");
    console.log("File deleted");
});