commands:Register("maxplayers", function(playerid, args, argsCount, silent, prefix)
    print("Max players: " .. server:GetMaxPlayers())
end)
