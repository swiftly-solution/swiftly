using SwiftlyS2.API.Scripting;

Events.AddEventHandler("OnPlayerDeath", (Events.Event @e) => {
    var playerid = @e.GetInt("userid");    // Retrieve the ID of the player who died.
    var attackerid = @e.GetInt("attacker"); // Retrieve the ID of the player who attacked.
    var headshot = @e.GetBool("headshot"); // Check if the kill was a headshot.
    var noscope = @e.GetBool("noscope");   // Check if the kill was performed without a scope.

    @e.SetBool("headshot", true);
    @e.SetBool("wipe", true);
    @e.SetBool("noscope", true);
    return EventResult.Continue
});