function export(exportName, callback)
    AddEventHandler("export:"..GetCurrentPluginName()..":"..exportName, function(event, ...)
        event:SetReturn(callback(...))
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
                    local eventRt, eventData = TriggerEvent("export:"..plugin..":"..key, ...)
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