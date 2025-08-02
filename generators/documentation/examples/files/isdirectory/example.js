commands.register("isdir", (playerId, args, argc, silent, prefix) => {
    if (files.IsDirectory("test")) {
        console.log("This is a folder");
    } else {
        console.log("Not a folder");
    }
});