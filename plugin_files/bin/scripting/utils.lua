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
            local cbaseentity = fetchedPlayer:CBaseEntity()
            if cbaseentity then
                if cbaseentity.TeamNum == teamSelector[target] then
                    table.insert(matchedPlayers, fetchedPlayer)
                    goto findplayersbytargetcontinue
                end
            end
        end

        --[[ life state ]]
        if lifeStateSelector[target] then
            local cbaseentity = fetchedPlayer:CBaseEntity()
            if cbaseentity then
                if cbaseentity.LifeState == lifeStateSelector[target] then
                    table.insert(matchedPlayers, fetchedPlayer)
                    goto findplayersbytargetcontinue
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
            if cbaseplayercontroller.PlayerName:find(target) then
                table.insert(matchedPlayers, fetchedPlayer)
                goto findplayersbytargetcontinue
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