local eventHandlers = {}
local msgpack_unpack = msgpack.unpack
local msgpack_pack = msgpack.pack
local table_unpack = table.unpack

local needsCasting = {
    ["CCheckTransmitInfo"] = true
}

AddGlobalEvents(function(event, eventSource, eventName, eventData)
    if not eventHandlers[eventName] then return EventResult.Continue end
    if #eventHandlers[eventName] <= 0 then return EventResult.Continue end

    local data = msgpack_unpack(eventData)
    if not data then return end
    if type(data) ~= "table" then return end

    local newdata = {}
    local skipNext = false
    for i = 1, #data do
        if not skipNext then
            newdata[#newdata + 1] = data[i]
            if type(data[i]) == "string" then
                local first = data[i]:byte(1)
                local second = data[i]:byte(2)
                if ((first == 48 and second == 120) or (data[i] == "(null)")) and (IsSDKClass(data[i + 1]) or needsCasting[data[i + 1]]) then
                    if IsSDKClass(data[i + 1]) or needsCasting[data[i + 1]] then
                        newdata[#newdata] = _G[data[i + 1]](data[i])
                        skipNext = true
                    end
                end
            end
        else
            skipNext = false
        end
    end

    for i = 1, #eventHandlers[eventName] do
        local handle = eventHandlers[eventName][i].handle
        if type(handle) == "function" then
            local result = (handle(event, table_unpack(newdata)) or EventResult.Continue)
            if result ~= EventResult.Continue then return result end
        end
    end

    return EventResult.Continue
end)

local eventRegistryIndex = 50

function AddEventHandler(eventName, cb)
    if not eventHandlers[eventName] then eventHandlers[eventName] = {} end

    eventRegistryIndex = eventRegistryIndex + 1
    table.insert(eventHandlers[eventName], { eventRegistryIndex = eventRegistryIndex, handle = cb })

    RegisterEventHandlerPlugin(eventName)

    return { key = eventRegistryIndex, name = eventName }
end

function RemoveEventHandler(eventData)
    if not eventData.key or not eventData.name then
        print("Error: Invalid event data passed to RemoveEventHandler.")
        return
    end
    if not eventHandlers[eventData.name] then eventHandlers[eventData.name] = {} end

    for i = 1, #eventHandlers[eventData.name] do
        if eventHandlers[eventData.name].eventRegistryIndex == eventData.key then
            table.remove(eventHandlers[eventData.name], i)
            break
        end
    end

    if #eventHandlers[eventData.name] == 0 then
        RemoveEventHandlerPlugin(eventData.name)
    end
end

function TriggerEvent(eventName, ...)
    local encodedData = msgpack_pack({ ... })

    local eventResult, eventData, _ = table_unpack(TriggerEventInternal(eventName, encodedData))
    return eventResult, eventData
end
