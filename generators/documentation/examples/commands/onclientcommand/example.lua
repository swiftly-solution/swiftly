AddEventHandler("OnClientCommand", function(event, playerid, command)
    print(string.format("Player %d used command '%s'", playerid, command))
    return EventResult.Continue
end)
