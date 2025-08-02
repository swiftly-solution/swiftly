commands:Register("maxplayers", function(playerid, args, argsCount, silent, prefix)
    print("Maximum players: " .. playermanager:GetPlayerCap())
end)
