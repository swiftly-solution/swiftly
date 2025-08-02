commands:Register("isdir", function(playerid, args, argsCount, silent, prefix)
    if files:IsDirectory("test") then
        print("This is a folder")
    else
        print("Not a folder")
    end
end)
