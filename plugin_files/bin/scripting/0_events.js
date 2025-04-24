const eventHandlers = {}

const LoadEventFile = (global) => {
    AddGlobalEvents((event, eventName, eventData) => {
        if (!eventHandlers.hasOwnProperty(eventName)) return EventResult.Continue
        if (eventHandlers[eventName].length <= 0) return EventResult.Continue

        eventData.unshift(event);

        const handlers = eventHandlers[eventName]
        for (let i = 0; i < handlers.length; i++) {
            if ((typeof handlers[i].handle) == "function") {
                let result = (handlers[i].handle.apply(null, eventData));
                if (result == null || result == undefined) result = EventResult.Continue;
                if (result != EventResult.Continue) return result
            }
        }

        return EventResult.Continue
    })

    AddGlobalEventsJSON((event, eventName, eventData) => {
        if (!eventHandlers.hasOwnProperty(eventName)) return EventResult.Continue
        if (eventHandlers[eventName].length <= 0) return EventResult.Continue

        eventData = JSON.parse(eventData)
        eventData.unshift(event);

        const handlers = eventHandlers[eventName]
        for (let i = 0; i < handlers.length; i++) {
            if ((typeof handlers[i].handle) == "function") {
                let result = (handlers[i].handle.apply(null, eventData));
                if (result == null || result == undefined) result = EventResult.Continue;
                if (result != EventResult.Continue) return result
            }
        }

        return EventResult.Continue
    })

    let eventRegistryIndex = 50

    global.AddEventHandler = (eventName, cb) => {
        if (!eventHandlers.hasOwnProperty(eventName)) eventHandlers[eventName] = []

        eventRegistryIndex = eventRegistryIndex + 1
        eventHandlers[eventName].push({ eventRegistryIndex, handle: cb })

        RegisterEventHandlerPlugin(eventName)

        return { key: eventRegistryIndex, name: eventName }
    }

    global.RemoveEventHandler = (eventData) => {
        if (typeof (eventData) != "object" || !eventData.key || !eventData.name) {
            console.log("Error: Invalid event data passed to RemoveEventHandler.")
            return
        }
        if (!eventHandlers.hasOwnProperty(eventData.name)) eventHandlers[eventData.name] = []

        for (let i = 0; i < eventHandlers[eventData.name]; i++) {
            if (eventHandlers[eventData.name].eventRegistryIndex == eventData.key) {
                eventHandlers[eventData.name].splice(i, 1)
                break
            }
        }

        if (eventHandlers[eventData.name].length == 0) {
            RemoveEventHandlerPlugin(eventData.name)
        }
    }

    global.TriggerEvent = (eventName, ...args) => {
        return TriggerEventInternal(eventName, JSON.stringify(args))
    }
}

LoadEventFile(globalThis)