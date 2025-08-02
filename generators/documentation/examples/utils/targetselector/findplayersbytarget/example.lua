commands:Register("getct", function(playerid, args, argsCount, silent, prefix)
    local players = FindPlayersByTarget("@ct", true)
    print("There are " .. #players .. " in CT.")
end)
