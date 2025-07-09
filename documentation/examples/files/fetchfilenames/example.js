commands.register("fetchfiles", (playerId, args, argc, silent, prefix) => {
    const filesList = files.FetchFileNames("addons/swiftly/configs");
    console.log("All configs: " + filesList.join(", "));
});