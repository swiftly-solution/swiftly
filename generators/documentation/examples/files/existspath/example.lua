commands:Register("exists", function(playerid, args, argsCount, silent, prefix)
    if files:ExistsPath("test.json") then
        print("Config file present")
    else
        print("Config file not found")
    end
end)
