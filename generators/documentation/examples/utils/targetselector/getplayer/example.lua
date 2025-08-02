commands:Register("player", function(playerid, args, argsCount, silent, prefix)
    local player = GetPlayer(playerid)
    if player then
        print("This player is on the server, now we can check if it's also a valid player")
    else
        print("This player is not on server")
    end
end)
