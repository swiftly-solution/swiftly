commands:Register("configfetch", function(playerid, arguments, arguments_count, silent, prefix)
    local value = config:Fetch("configuration.test2")
    if value then
        if type(value) == "table" then
            print("Configuration is a table:")
            for k, v in pairs(value) do
                print(k, v)
            end
        else
            print("Configuration value:", value)
        end
    else
        print("Configuration key not found.")
    end
end)
