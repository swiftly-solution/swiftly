using SwiftlyS2.API.Scripting;

var event = Events.AddEventHandler("OnPlayerConnectFull", (Events.Event @e) => {
    var player = Generic.GetPlayer(@e.GetInt("userid"));
    if(!player) return EventResult.Continue;
    Console.WriteLine($"Player {player.GetSteamID()} connected.");
    return EventResult.Continue
});

Commands.Register("removeevent", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Events.RemoveEventHandler(event);
});