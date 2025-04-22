local table_unpack = table.unpack

function export(exportName, callback)
    AddEventHandler("export:"..GetCurrentPluginName()..":"..exportName, function(event, ...)
        local elems = {...}
        for i=1,#elems do
            if type(elems[i]) == "string" then
                local res, data = serpent.load(elems[i], { safe = false })
                if res == true and type(data) == "function" then
                    elems[i] = data
                end
            end
        end

        event:SetReturn(callback(table_unpack(elems)))
        return EventResult.Stop
    end)
end

exports = {}

setmetatable(exports, {
    __index = function(tbl, pluginName)
        local plugin = pluginName

        return setmetatable({}, {
            __index = function(tbl, key)
                return function(self, ...)
                    local elems = {...}
                    for i=1,#elems do
                        if type(elems[i]) == "function" then
                            elems[i] = serpent.dump(elems[i])
                        end
                    end

                    local eventRt, eventData = TriggerEvent("export:"..plugin..":"..key, table_unpack(elems))
                    if eventRt ~= EventResult.Stop then
                        print("Export '"..key.."' in '"..plugin.."' doesn't exists.")
                    end
                    return eventData:GetReturn()
                end
            end,

            __newindex = function(tbl, key, val) 
                print("You can't create a new index on this table.")
            end
        })
    end,

    __newindex = function(tbl, key, val) 
        print("You can't create a new index on this table.")
    end
})