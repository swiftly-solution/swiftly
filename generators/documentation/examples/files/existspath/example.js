commands.register("exists", (playerId, args, argc, silent, prefix) => {
    if (files.ExistsPath("test.json")) {
        console.log("Config file present");
    } else {
        console.log("Config file not found");
    }
});