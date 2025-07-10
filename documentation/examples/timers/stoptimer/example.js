commands.Register("startstop", (playerid, args, argc, silent, prefix) => {
    let timer = SetTimer(1000, function () { })
    SetTimeout(5000, function () {
        StopTimer(timer)
    })
});