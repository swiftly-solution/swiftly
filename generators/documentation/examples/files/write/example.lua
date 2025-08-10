commands:Register("write", function(playerid, args, argsCount, silent, prefix)
    files:Write("addons/swiftly/important/important.txt", "Important data", true)
    print("File written")
end)
