commands:Register("currentmap", function(playerid, args, argsCount, silent, prefix)
    print("Current map is: " .. server:GetMap())
end)
