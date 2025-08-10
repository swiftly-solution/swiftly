AddEventHandler("OnPlayerDeath", function(event)
    local playerid = event:GetInt("userid")     -- Retrieve the ID of the player who died.
    local attackerid = event:GetInt("attacker") -- Retrieve the ID of the player who attacked.
    local headshot = event:GetBool("headshot")  -- Check if the kill was a headshot.
    local noscope = event:GetBool("noscope")    -- Check if the kill was performed without a scope.

    event:SetBool("headshot", true)
    event:SetBool("wipe", true)
    event:SetBool("noscope", true)
    return EventResult.Continue
end)
