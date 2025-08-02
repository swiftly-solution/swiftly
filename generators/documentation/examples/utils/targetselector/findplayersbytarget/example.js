commands.Register("getct", (playerid, args, argsCount, silent, prefix) => {
    let players = FindPlayersByTarget("@ct", true)
    print(`There are ${players.length} in CT.`)
})
