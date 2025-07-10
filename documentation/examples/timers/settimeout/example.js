commands.Register("settimeout", (playerid, args, argc, silent, prefix) => {
    SetTimeout(3000, function () {
        console.log("3 seconds elapsed!")
    });
});