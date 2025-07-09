commands.register("createdir", (playerId, args, argc, silent, prefix) => {
    if (files.CreateDirectory("addons/swiftly/plugins/test")) {
        console.log("Directory created successfully");
    } else {
        console.log("Failed to create directory");
    }
});