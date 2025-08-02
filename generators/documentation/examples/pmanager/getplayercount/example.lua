commands:Register("players", function(playerid, args, argsCount, silent, prefix)
    print("There are: " .. playermanager:GetPlayerCount() .. " players online!")
end)
