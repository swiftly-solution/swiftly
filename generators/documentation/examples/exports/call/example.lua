commands:Register("testexport", function(playerid, args, argsCount, silent, prefix)
    local player = GetPlayer(playerid)
    if not player or not player:IsValid() then return end

    if not exports["admins"]:HasFlags(playerid, "b") then
        return player:SendMsg(MessageType.Chat, "You don't have the right flag for this command!")
    end
end)
