commands:Register("fetchdirs", function(playerid, args, argsCount, silent, prefix)
    local dirs = files:FetchDirectories("addons/swiftly/plugins")
    for i = 1, #dirs do
        print("Found plugin: " .. dirs[i])
    end
end)
