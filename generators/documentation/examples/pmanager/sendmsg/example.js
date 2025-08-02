commands.Register("players", (playerId, args, argc, silent, prefix) => {
    playermanager.SendMsg(MessageType.Chat, "Hello there!")
});