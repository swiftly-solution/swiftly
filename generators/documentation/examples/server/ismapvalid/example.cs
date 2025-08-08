using SwiftlyS2.API.Scripting;

Commands.Register("tickcount", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    if(Server.IsMapValid("de_nuke")){
        Console.WriteLine("The map de_nuke is valid!");
    } else {
        Console.WriteLine("The map de_nuke is not valid!");
    }
});