commands:Register("append", function(playerid, args, argsCount, silent, prefix)
    files:Append("test/test.log", "Test!", true)
end)
