commands:Register("credits", function(playerid, args, argsCount, silent, prefix)
    local player = GetPlayer(playerid)
    if not player or not player:IsValid() then return end
    local credits = 50
    player:SendMsg(MessageType.Chat, FetchTranslation("first_plugin.credits", playerid):gsub("{credits}", credits))
end)

--[[
Translation File: addons/swiftly/translations/translation.first_plugin.json

{
    "credits": {
        "en": "Your current credits are {credits}!",
        "ro": "In momentul asta ai {credits} credite!"
    }
}
]]
