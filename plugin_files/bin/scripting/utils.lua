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

function FindPlayersByTarget(target, matchbots, playerid)
    if matchbots == nil then matchbots = true end
    local matchedPlayers = {}
    target = tostring(target)

    if target == "@me" then
        return {GetPlayer(playerid)}
    end

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
                if i == tonumber(playerid) then
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

        local result, eventRet = TriggerEvent("FindPlayerByTarget", i, target, playerid)
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
    for split in string.gmatch(str or "", "[^"..split.."]+") do 
        table.insert(splitted, split) 
    end
    return splitted
end

--- @param str string
--- @return string
string.trim = function(str)
    return (str:gsub("^%s*(.-)%s*$", "%1"))
end


--- @param value any The value to be matched against. Can be a number or a string.
--- @param cases table
--- @return any Returns
switch = function(value, cases)
    local case = cases[value]
    if case then
        if type(case) == "function" then
            return case()
        else
            return case
        end
    elseif cases.default then
        if type(cases.default) == "function" then
            return cases.default()
        else
            return cases.default
        end
    end
end

--- @param tbl table The table to be mapped.
--- @param func function A function that takes a value and key as parameters and returns a new value.
--- @return table A new table with the transformed values.
table.map = function(tbl, func)
    local result = {}
    for key, value in next, tbl do
        result[key] = func(value, key)
    end
    return result
end

--- @param tbl table The table to be filtered.
--- @param predicate function A function that takes a value and key as parameters and returns a boolean.
--- @return table A new table containing only the elements for which the predicate returned true.
table.filter = function(tbl, predicate)
    local result = {}
    local index = 1
    for key, value in next, tbl do
        if predicate(value, key) then
            result[index] = value
            index = index + 1
        end
    end
    return result
end
--- @param tbl table The table to search.
--- @param value any The value to search for.
--- @return boolean True if the value exists in the table, false otherwise.
table.contains = function(tbl, value)
    for _, val in next, tbl do
        if val == value then
            return true
        end
    end
    return false
end

--- @param tbl table The table to search.
--- @param value any the key to search for.
--- @return key number The key returned.
table.find = function(tbl, value)
    for key, val in next, tbl do
        if val == value then
            return key
        end
    end
    return nil
end

local weaponlist = {
    ["weapon_ak47"] = true,
    ["weapon_aug"] = true,
    ["weapon_awp"] = true,
    ["weapon_bizon"] = true,
    ["weapon_c4"] = true,
    ["weapon_cz75a"] = true,
    ["weapon_deagle"] = true,
    ["weapon_decoy"] = true,
    ["weapon_elite"] = true,
    ["weapon_famas"] = true,
    ["weapon_fiveseven"] = true,
    ["weapon_flashbang"] = true,
    ["weapon_g3sg1"] = true,
    ["weapon_galilar"] = true,
    ["weapon_glock"] = true,
    ["weapon_healthshot"] = true,
    ["weapon_hegrenade"] = true,
    ["weapon_incgrenade"] = true,
    ["weapon_knife"] = true,
    ["weapon_m249"] = true,
    ["weapon_m4a1"] = true,
    ["weapon_mac10"] = true,
    ["weapon_mag7"] = true,
    ["weapon_molotov"] = true,
    ["weapon_mp5sd"] = true,
    ["weapon_mp7"] = true,
    ["weapon_mp9"] = true,
    ["weapon_negev"] = true,
    ["weapon_nova"] = true,
    ["weapon_p2000"] = true,
    ["weapon_p250"] = true,
    ["weapon_p90"] = true,
    ["weapon_sawedoff"] = true,
    ["weapon_scar20"] = true,
    ["weapon_sg556"] = true,
    ["weapon_smokegrenade"] = true,
    ["weapon_ssg08"] = true,
    ["weapon_tec9"] = true,
    ["weapon_ump45"] = true,
    ["weapon_usp_silencer"] = true,
    ["weapon_xm1014"] = true
}

-- In the future, we may need to add more items here.
-- For now, I've only added the ones that are working.
local itemlist = {
    ["item_assaultsuit"] = true,  -- Kevlar + Helmet
    ["item_defuser"] = true,      -- Defuse Kit
    ["item_kevlar"] = true        -- Kevlar
}

-- Function to check if the weapon is valid
function IsValidWeapon(weapon)
    return weaponlist[weapon] ~= nil
end

-- Function to check if the item is valid
function IsValidItem(item)
    return itemlist[item] ~= nil
end
