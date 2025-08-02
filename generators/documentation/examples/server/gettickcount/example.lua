commands:Register("tickcount", function(playerid, args, argsCount, silent, prefix)
    print("Tick count: " .. server:GetTickCount())
end)
