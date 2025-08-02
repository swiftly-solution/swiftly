AddEventHandler("OnClientCommand", (event, playerid, command) => {
    console.log(`Player ${playerid} used command '${command}'`)
    return EventResult.Continue
})