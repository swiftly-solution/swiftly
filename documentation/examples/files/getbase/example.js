commands.register("getbase", (playerId, args, argc, silent, prefix) => {
    const name = files.GetBase("cfg/autoexec.cfg");
    console.log("Base filename: " + name);
});