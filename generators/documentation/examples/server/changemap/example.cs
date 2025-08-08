using SwiftlyS2.API.Scripting;

Commands.Register("changemap", (int playerid, string[] arguments, int count, bool silent, string prefix) => {
    Server.ChangeMap("de_dust2", false);           // Example for not-workshop map.
    Server.ChangeMap("random_workshop_map", true); // Example for workshop map
});