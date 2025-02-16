const eventHandlers = {}

const needsCasting = ["CCheckTransmitInfo"]

globalThis.sdk = new Proxy({}, {
    get: (obj, key, receiver) => {
        if(key == "CCheckTransmitInfo") return CCheckTransmitInfo;
        else if(IsTypeClass(key)) return GenerateTypeFactory(key);
        else if(IsSDKClass(key)) return GenerateSDKFactory(key).call;
        else return undefined;
    },
    set: (target, key, val, recv) => {
        throw SyntaxError("You cannot set values to SDK.");
    }
})

const LoadEventFile = (global) => {
    global.msgpack_unpack = null
    global.msgpack_pack = null

    function setupMsgpack() {
        global.msgpack_pack = data => msgpack.pack(data)
        global.msgpack_unpack = data => msgpack.unpack(data)
    }
    
    AddGlobalEvents((event, eventSource, eventName, eventData) => {
        if(global.msgpack_unpack == null || global.msgpack_pack == null) setupMsgpack()
    
        if (!eventHandlers.hasOwnProperty(eventName)) return EventResult.Continue
        if (eventHandlers[eventName].length <= 0) return EventResult.Continue
    
        let data = msgpack_unpack(eventData)
        if(!data) return EventResult.Continue
        if(typeof data != "object") return EventResult.Continue
    
        let newdata = []
        let skipNext = false
        for(let i = 0; i < data.length; i++) {
            if(skipNext) {
                newdata.push(data[i])
                if(typeof data[i] == "string") {
                    if((data[i].startsWith("0x") || data[i] == "(null)") && (IsSDKClass(data[i+1]) || needsCasting.includes(data[i+1]))) {
                        newdata[newdata.length-1] = global["sdk"][data[i+1]](data[i])
                        skipNext = true
                    }
                }
            } else {
                skipNext = false
            }
        }
    
        newdata.unshift(event);
    
        const handlers = eventHandlers[eventName]
        for(let i = 0; i < handlers.length; i++) {
            if((typeof handlers[i].handle) == "function") {
                const result = (handlers[i].handle.apply(global, newdata) || EventResult.Continue);
                if(result != EventResult.Continue) return result
            }
        }
    
        return EventResult.Continue
    })
    
    let eventRegistryIndex = 50
    
    global.AddEventHandler = (eventName, cb) => {
        if(!eventHandlers.hasOwnProperty(eventName)) eventHandlers[eventName] = []
    
        eventRegistryIndex = eventRegistryIndex + 1
        eventHandlers[eventName].push({ eventRegistryIndex, handle: cb })
    
        RegisterEventHandlerPlugin(eventName)
    
        return { key: eventRegistryIndex, name: eventName }
    }
    
    global.RemoveEventHandler = (eventData) => {
        if(typeof(eventData) != "object" || !eventData.key || !eventData.name) {
            console.log("Error: Invalid event data passed to RemoveEventHandler.")
            return
        }
        if(!eventHandlers.hasOwnProperty(eventData.name)) eventHandlers[eventData.name] = []
    
        for(let i = 0; i < eventHandlers[eventData.name]; i++) {
            if(eventHandlers[eventData.name].eventRegistryIndex == eventData.key) {
                eventHandlers[eventData.name].splice(i, 1)
                break
            }
        }
    
        if(eventHandlers[eventData.name].length == 0) {
            RemoveEventHandlerPlugin(eventData.name)
        }
    }
    
    global.TriggerEvent = (eventName, ...args) => {
        if(global.msgpack_unpack == null || global.msgpack_pack == null) setupMsgpack()

        const encdata = global.msgpack_pack(args);
        return TriggerEventInternal(eventName, encdata)
    }
}

LoadEventFile(globalThis)