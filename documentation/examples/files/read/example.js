commands.register("read", (playerId, args, argc, silent, prefix) => {
    const content = files.Read("addons/swiftly/configs/settings.json");
    if (content) {
        console.log("File contents: " + content);
    } else {
        console.log("Failed to read file");
    }
});