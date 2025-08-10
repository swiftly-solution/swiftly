commands:Register("fetchfiles", function(playerid, args, argsCount, silent, prefix)
    local filesList = files:FetchFileNames("addons/swiftly/configs")
    print("All configs: " .. table.concat(filesList, ", "))
end)
