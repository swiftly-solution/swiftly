commands:Register("configexists", function(playerid, arguments, arguments_count, silent, prefix)
    if config:Exists("configuration.test") then
        print("Configuration key 'test' exists!")
    else
        print("Configuration 'test' does not exist!")
    end
end)
