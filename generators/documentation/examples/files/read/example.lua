commands:Register("read", function(playerid, args, argsCount, silent, prefix)
    local content = files:Read("addons/swiftly/configs/settings.json")
    if content then
        print("File contents: " .. content)
    else
        print("Failed to read file")
    end
end)
