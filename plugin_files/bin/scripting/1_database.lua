local databaseRequestsQueue = {}
local json_decode = json.decode

AddEventHandler("OnDatabaseActionPerformed", function(event, databaseRequestID, result, err)
    if not databaseRequestsQueue[databaseRequestID] then return EventResult.Continue end

    local debuginfo = debug.getinfo(databaseRequestsQueue[databaseRequestID], "S")
    local stackid = RegisterCallstack(GetCurrentPluginName(),
        string.format("DatabaseCallback(path=%s,lines=%d..%d)", debuginfo.short_src, debuginfo.linedefined,
            debuginfo.lastlinedefined))

    local status, err = pcall(databaseRequestsQueue[databaseRequestID], err, json_decode(result) or {})
    if not status then
        print("An error has been occured while trying to execute a query.\nError: " .. err)
    end

    databaseRequestsQueue[databaseRequestID] = nil
    UnregisterCallstack(GetCurrentPluginName(), stackid)

    return EventResult.Stop
end)

function Database(name)
    return {
        dbval = DB(name),
        Query = function(self, query, callback)
            if type(callback) ~= "function" then return end
            
            local callback_uuid = uuid()
            if callback then databaseRequestsQueue[callback_uuid] = callback end
            self.dbval:Query(query, callback_uuid)
        end,
        IsConnected = function(self)
            return self.dbval:IsConnected()
        end,
        EscapeString = function(self, value)
            return self.dbval:EscapeString(value)
        end,
        GetVersion = function(self)
            return self.dbval:GetVersion()
        end,
        QueryParams = function(self, query, arguments, callback)
            if type(query) ~= "string" then query = tostring(query) end
            if type(arguments) ~= "table" then arguments = {} end

            local has_ats = (query:find("@") ~= nil)
            local has_brace = (query:find("{") ~= nil)
            local has_bracket = (query:find("[") ~= nil)

            for k, v in next, arguments, nil do
                local key = (type(k) == "string" and k or tostring(k))
                local value = self:EscapeString(v)

                if has_ats then query, _ = query:gsub("@" .. key, value) end
                if has_brace then query, _ = query:gsub("{" .. key .. "}", value) end
                if has_bracket then query, _ = query:gsub("[" .. key .. "]", value) end
            end

            self:Query(query, callback)
        end,
        QueryBuilder = function(self)
            local qbTable = self.dbval:QueryBuilder()
            if qbTable == nil then return nil end
            return _G[qbTable](self)
        end
    }
end
