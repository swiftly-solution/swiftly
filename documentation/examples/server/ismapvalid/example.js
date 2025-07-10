commands.Register("isvalid", (playerId, args, argc, silent, prefix) => {
    if (server.IsMapValid("de_nuke")) {
        console.log("The map: de_nuke is valid");
    } else {
        console.log("The map: de_nuke is not valid. ");
    }
});