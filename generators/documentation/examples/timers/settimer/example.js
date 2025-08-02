commands.Register("settimer", (playerid, args, argc, silent, prefix) => {
    SetTimer(1000, function () {
        console.log("This runs every second!")
    });
});