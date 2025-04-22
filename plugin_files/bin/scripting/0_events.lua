local eventHandlers = {}
local table_unpack = table.unpack

local function CallEventCallbacks(event, eventName, ...)
    for i = 1, #eventHandlers[eventName] do
        local handle = eventHandlers[eventName][i].handle
        if type(handle) == "function" then
            local result = (handle(event, ...) or EventResult.Continue)
            if result ~= EventResult.Continue then return result end
        end
    end

    return EventResult.Continue
end

AddGlobalEvents(function(event, eventName, eventData)
    if not eventHandlers[eventName] then return EventResult.Continue end
    if #eventHandlers[eventName] <= 0 then return EventResult.Continue end

    return CallEventCallbacks(event, eventName, table_unpack(eventData))
end)

AddGlobalEventsJSON(function(event, eventName, eventData)
    if not eventHandlers[eventName] then return EventResult.Continue end
    if #eventHandlers[eventName] <= 0 then return EventResult.Continue end

    return CallEventCallbacks(event, eventName, table_unpack(json.decode(eventData)))
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
    local eventResult, eventData, _ = table_unpack(TriggerEventInternal(eventName, json.encode({...})))
    return eventResult, eventData
end