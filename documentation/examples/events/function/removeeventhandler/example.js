let event = AddEventHandler("OnPlayerConnectFull", (event) => {
    let player = GetPlayer(event.GetInt("userid"))
    if (!player) return;
    console.log(`Player ${player.GetSteamID()} connected.`)
    return EventResult.Continue
})

commands.Register("removeevent", (playerid, arguments, arguments_count, silent, prefix) -> {
    RemoveEventHandler(event) // Removes the event handler for OnPlayerConnectFull
})
