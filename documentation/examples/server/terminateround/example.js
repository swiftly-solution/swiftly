commands.Register("endround", (playerId, args, argc, silent, prefix) => {
    server.TerminateRound(0.5, RoundEndReason_t.TerroristsPlanted);
});