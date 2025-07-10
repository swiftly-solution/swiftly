commands.Register("player", (playerid, args, argsCount, silent, prefix) => {
    let player = GetPlayer(playerid)
    if (player) console.log("This player is on the server, now we can check if it's also a valid player")
    else console.log("This player is not on server")
})
