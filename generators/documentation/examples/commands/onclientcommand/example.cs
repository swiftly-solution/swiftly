using SwiftlyS2.API.Scripting;

Events.AddEventHandler("OnClientCommand", (Events.Event @e, int playerid, string command) =>
{
    var player = Generic.GetPlayer(playerid);
    if(!player) return EventResult.Continue;

    Console.WriteLine($"Player: {playerid} used command '{command}'");
    return EventResult.Continue;
})