
local eventHandlers = {}

AddGlobalEvents(function(event, eventSource, eventName, eventData)
    if not eventHandlers[eventName] then return end
    if not eventHandlers[eventName].handlers then return end

    local data = msgpack.unpack(eventData)
    if not data then return end
    if type(data) ~= "table" then return end

    for idx,handle in next,eventHandlers[eventName].handlers,nil do
        if type(handle) == "function" then
            local result = handle(event, table.unpack(data))
            if result ~= EventResult.Continue then return result end
        end
    end

    return EventResult.Continue
end)

local eventRegistryIndex = 50

function AddEventHandler(eventName, cb)
    if not eventHandlers[eventName] then eventHandlers[eventName] = {} end
    if not eventHandlers[eventName].handlers then eventHandlers[eventName].handlers = {} end

    eventRegistryIndex = eventRegistryIndex + 1
    eventHandlers[eventName].handlers[eventRegistryIndex] = cb

    RegisterEventHandlerPlugin(eventName)

    return { key = eventRegistryIndex, name = eventName }
end

function RemoveEventHandler(eventData)
    if not eventData.key or not eventData.name then
        print("Error: Invalid event data passed to RemoveEventHandler.")
        return
    end

    eventHandlers[eventData.name].handlers[eventData.key] = nil
end

function TriggerEvent(eventName, ...)
    local encodedData = msgpack.pack({...})

    local eventResult, eventData, _ = table.unpack(TriggerEventInternal(eventName, encodedData))
    return eventResult, eventData
end