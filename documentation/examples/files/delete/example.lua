commands:Register("delete", function(playerid, args, argsCount, silent, prefix)
    files:Delete("addons/swiftly/logs/log_1.log")
    print("File deleted")
end)
