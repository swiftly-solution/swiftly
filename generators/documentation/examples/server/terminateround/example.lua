commands:Register("endround", function(playerid, args, argsCount, silent, prefix)
    server:TerminateRound(0.5, RoundEndReason_t.TerroristsPlanted)
end)
