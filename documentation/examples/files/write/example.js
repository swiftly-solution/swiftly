commands.register("write", (playerId, args, argc, silent, prefix) => {
    files.Write("addons/swiftly/important/important.txt", "Important data", true);
    console.log("File written");
});