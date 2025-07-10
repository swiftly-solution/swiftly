commands:Register("startstop", function(playerid, args, argsCount, silent, prefix)
    local timer = SetTimer(1000, function() end)
    SetTimeout(5000, function()
        StopTimer(timer)
    end)
    -- Start and stop timer after 5 seconds.
end)
