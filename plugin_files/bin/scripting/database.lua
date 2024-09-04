databaseRequestsQueue = {}

AddEventHandler("OnDatabaseActionPerformed", function(event, databaseRequestID, result, err)
    if not databaseRequestsQueue[databaseRequestID] then return EventResult.Continue end

    local status, err = pcall(databaseRequestsQueue[databaseRequestID], err, json.decode(result) or {})
    if not status then
        print("An error has been occured while trying to execute a query.\nError: "..err)
    end

    databaseRequestsQueue[databaseRequestID] = nil

    return EventResult.Stop
end)