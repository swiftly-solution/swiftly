databaseRequestsQueue = {}
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
