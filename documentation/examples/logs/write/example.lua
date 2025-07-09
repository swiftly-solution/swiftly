AddEventHandler("OnPlayerConnectFull", function(event)
    local playerid = event:GetInt("userid")
    local player = GetPlayer(playerid)
    if not player or not player:IsValid() then return end

    if not player:CBasePlayerController():IsValid() then return end
    logger:Write(LogType_t.Common, "The player: " .. player:CBasePlayerController().PlayerName .. " joined the server!")
end)
