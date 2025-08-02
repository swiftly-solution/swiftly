commands:Register("removetext", function(playerid, args, argsCount, silent, prefix)
    local textId = vgui:ShowText(playerid, Color(255, 255, 255, 255), "Temp Message", 0.5, 0.5, "Arial")
    vgui:RemoveText(textId)
end)
