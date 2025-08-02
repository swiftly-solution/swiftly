commands:Register("configreload", function(playerid, arguments, arguments_count, silent, prefix)
    config:Reload("configuration")
    print("Configuration reloaded for 'configuration'")
end)
