commands:Register("createdir", function(playerid, args, argsCount, silent, prefix)
    if files:CreateDirectory("addons/swiftly/plugins/test") then
        print("Directory created successfully")
    else
        print("Failed to create directory")
    end
end)
