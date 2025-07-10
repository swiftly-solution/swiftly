commands.Register("nexttick", (playerid, args, argc, silent, prefix) => {
    NextTick(() => {
        console.log("This runs at next server tick!")
    })
});