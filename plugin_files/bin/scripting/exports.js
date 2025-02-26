function LoadExports(global) {
    let pluginProxyCache = {}

    global.exp = (exportName, callback) => {
        AddEventHandler(`export:${GetCurrentPluginName()}:${exportName}`, (event, ...args) => {
            event.SetReturn(callback.apply(global, args))
            return EventResult.Stop
        })
    }

    global.exports = new Proxy({}, {
        get: (tbl, pluginName) => {
            if(!pluginProxyCache[pluginName]) {
                pluginProxyCache[pluginName] = new Proxy({}, {
                    get: (tbl, funcName) => {
                        return (...args) => {
                            let [eventRt, eventData] = TriggerEvent(`export:${pluginName}:${funcName}`, ...args)
                            if (eventRt != EventResult.Stop) {
                                console.log(`Export '${funcName}' in '${pluginName}' doesn't exists.`)
                            }
                            return eventData.GetReturn()
                        }
                    },
                    set: (tbl, key, val) => {
                        console.log("You can't create a new value on this object.")
                        return false
                    }
                })
            }
            return pluginProxyCache[pluginName]
        },
        set: (tbl, key, val) => {
            console.log("You can't create a new value on this object.")
            return false
        }
    })
}

LoadExports(globalThis)