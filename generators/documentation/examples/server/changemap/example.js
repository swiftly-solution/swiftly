commands.Register("changemap", (playerId, args, argc, silent, prefix) => {
    server.ChangeMap("de_dust2", false); // Example for not-workshop map.
    server.ChangeMap("random_workshop_map", true); // Example for workshop map
});