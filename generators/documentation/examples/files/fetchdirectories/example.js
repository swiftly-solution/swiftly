commands.register("fetchdirs", (playerId, args, argc, silent, prefix) => {
    const dirs = files.FetchDirectories("addons/swiftly/plugins");
    for (let i = 0; i < dirs.length; i++) {
        console.log("Found plugin: " + dirs[i]);
    }
});