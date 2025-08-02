export("GetCredits", function(playerid)
    local player = GetPlayer(playerid)
    if not player then return 0 end
    if player:IsFakeClient() then return 0 end

    return player:GetVar("credits")
end)
