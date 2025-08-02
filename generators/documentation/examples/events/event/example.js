AddEventHandler("OnPlayerDeath", (event) => {
    let playerid = event.GetInt("userid") // Retrieve the ID of the player who died.
    let attackerid = event.GetInt("attacker") // Retrieve the ID of the player who attacked.
    let headshot = event.GetBool("headshot") // Check if the kill was a headshot.
    let noscope = event.GetBool("noscope") // Check if the kill was performed without a scope.

    event.SetBool("headshot", true)
    event.SetBool("wipe", true)
    event.SetBool("noscope", true)
    return EventResult.Continue
})
