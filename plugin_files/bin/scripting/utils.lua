local teamSelector = {
    ["@ct"] = Team.CT,
    ["@t"] = Team.T,
    ["@spec"] = Team.Spectator
}

local lifeStateSelector = {
    ["@alive"] = LifeState_t.LIFE_ALIVE,
    ["@dying"] = LifeState_t.LIFE_DYING,
    ["@dead"] = LifeState_t.LIFE_DEAD
}

function FindPlayersByTarget(target, matchbots)
    if matchbots == nil then matchbots = true end
    local matchedPlayers = {}
    target = tostring(target)

    for i=0,playermanager:GetPlayerCap()-1,1 do
        local fetchedPlayer = GetPlayer(i)
        if not fetchedPlayer then goto findplayersbytargetcontinue end

        if fetchedPlayer:IsFakeClient() and not matchbots then goto findplayersbytargetcontinue end

        if target == "@all" then
            table.insert(matchedPlayers, fetchedPlayer)
            goto findplayersbytargetcontinue
        end

        --[[ userid ]]
        if target:sub(1,1) == "#" then
            local playerid = target:sub(2)
            if playerid then
                if tostring(i):find(playerid) then
                    table.insert(matchedPlayers, fetchedPlayer)
                    goto findplayersbytargetcontinue
                end
            end
        end

        --[[ team ]]
        if teamSelector[target] then
            local cbaseentity = CBaseEntity(fetchedPlayer:CCSPlayerPawn():ToPtr())
            if cbaseentity then
                if cbaseentity:IsValid() then
                    if cbaseentity.TeamNum == teamSelector[target] then
                        table.insert(matchedPlayers, fetchedPlayer)
                        goto findplayersbytargetcontinue
                    end
                end
            end
        end

        --[[ life state ]]
        if lifeStateSelector[target] then
            local cbaseentity = CBaseEntity(fetchedPlayer:CCSPlayerPawn():ToPtr())
            if cbaseentity then
                if cbaseentity:IsValid() then
                    if cbaseentity.LifeState == lifeStateSelector[target] then
                        table.insert(matchedPlayers, fetchedPlayer)
                        goto findplayersbytargetcontinue
                    end
                end
            end
        end

        --[[ steamid, steamid64, name ]]
        if tostring(fetchedPlayer:GetSteamID()) == target or fetchedPlayer:GetSteamID2() == target then
            table.insert(matchedPlayers, fetchedPlayer)
            goto findplayersbytargetcontinue
        end

        local cbaseplayercontroller = fetchedPlayer:CBasePlayerController()
        if cbaseplayercontroller then
            if cbaseplayercontroller:IsValid() then
                if cbaseplayercontroller.PlayerName:find(target) then
                    table.insert(matchedPlayers, fetchedPlayer)
                    goto findplayersbytargetcontinue
                end
            end
        end

        local result, eventRet = TriggerEvent("FindPlayerByTarget", i, target)
        local returnValue = eventRet:GetReturn()
        if returnValue == true then
            table.insert(matchedPlayers, fetchedPlayer)
            goto findplayersbytargetcontinue
        end

        ::findplayersbytargetcontinue::
    end

    return matchedPlayers
end

function ReplyToCommand(playerid, prefix, str)
    if playerid == -1 then
        print(str)
    else
        local player = GetPlayer(playerid)
        if not player then return end
        if player:IsFakeClient() then return end
        player:SendMsg(MessageType.Chat, prefix.." "..str)
    end
end

local random = math.random
function uuid()
    math.randomseed(os.time())
    local template ='xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'
    return string.gsub(template, '[xy]', function (c)
        local v = (c == 'x') and random(0, 0xf) or random(8, 0xb)
        return string.format('%x', v)
    end)
end

function ComputePrettyTime(seconds)
    if seconds == 0 then return FetchTranslation("core.forever")
    elseif seconds < 60 then return FetchTranslation("core.seconds"):gsub("{TIME}", seconds)
    elseif seconds < 3600 then return FetchTranslation("core.minutes"):gsub("{TIME}", math.floor(seconds / 60))
    elseif seconds < 86400 then return FetchTranslation("core.hours"):gsub("{TIME}", math.floor(seconds / 3600))
    else return FetchTranslation("core.days"):gsub("{TIME}", math.floor(seconds / 86400)) end
end

string.split = function(str, split)
    local splitted = {}
    for split in string.gmatch(str, "[^"..split.."]+") do 
        table.insert(splitted, split) 
    end
    return splitted
end

--- @param str string
--- @return string
string.trim = function(str)
    return (str:gsub("^%s*(.-)%s*$", "%1"))
end