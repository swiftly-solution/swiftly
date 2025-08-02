commands:Register("configfetchsize", function(playerid, arguments, arguments_count, silent, prefix)
    local size = config:FetchArraySize("configuration.test3")
    if size > 0 then
        print("Array size:", size)
    else
        print("Configuration key is not an array or does not exist.")
    end
end)
