using SwiftlyS2.API.Scripting;

Commands.Register("player", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    var player = Generic.GetPlayer(playerid);
    if(player) {
        Console.WriteLine("This player is on the server, now we can check if it's also a valid player");
    } else {
        Console.WriteLine("This player is not on server");
    }
});