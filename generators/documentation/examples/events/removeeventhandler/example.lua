local event = AddEventHandler("OnPlayerConnectFull", function(event)
    local player = GetPlayer(event:GetInt("userid"))
    if not player then return end
    print("Player " .. tostring(player:GetSteamID()) .. " connected.")
    return EventResult.Continue
end)

commands:Register("removeevent", function(playerid, arguments, arguments_count, silent, prefix)
    RemoveEventHandler(event) -- Removes the event handler for OnPlayerConnectFull
end)
