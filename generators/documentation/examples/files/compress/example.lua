commands:Register("compress", function(playerid, args, argsCount, silent, prefix)
    if files:Compress("logs/error.log", "archives/errors.zip") then
        print("Compression succeeded")
    else
        print("Compression failed")
    end
end)
