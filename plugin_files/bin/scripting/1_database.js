function LoadDatabase(global) {
    global.databaseRequestsQueue = {}

    AddEventHandler("OnDatabaseActionPerformed", (event, databaseRequestID, result, err) => {
        if(!global.databaseRequestsQueue[databaseRequestID]) return;

        let stackid = RegisterCallstack(GetCurrentPluginName(), "DatabaseCallback")

        try {
            global.databaseRequestsQueue[databaseRequestID](err, JSON.parse(result))
        } catch(err) {
            console.log("An error has been occured while trying to execute a query.\nError: " + err)
        }

        delete databaseRequestsQueue[databaseRequestID];
        UnregisterCallstack(GetCurrentPluginName(), stackid)
        return EventResult.Stop
    })
}

LoadDatabase(globalThis)