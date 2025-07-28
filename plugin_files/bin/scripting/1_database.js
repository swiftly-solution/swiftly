function LoadDatabase(global) {
    global.databaseRequestsQueue = {}

    AddEventHandler("OnDatabaseActionPerformed", (event, databaseRequestID, result, err) => {
        if (!global.databaseRequestsQueue[databaseRequestID]) return;

        let stackid = RegisterCallstack(GetCurrentPluginName(), "DatabaseCallback")

        try {
            global.databaseRequestsQueue[databaseRequestID](err, JSON.parse(result))
        } catch (err) {
            console.log("An error has been occured while trying to execute a query.\nError: " + err)
        }

        delete databaseRequestsQueue[databaseRequestID];
        UnregisterCallstack(GetCurrentPluginName(), stackid)
        return EventResult.Stop
    })

    global.Database = (name) => {
        return {
            dbval: DB(name),
            Query: (query, callback) => {
                let callback_uuid = uuid()
                if (callback) databaseRequestsQueue[callback_uuid] = callback;
                this.dbval.Query(query, callback_uuid)
            },
            IsConnected: () => {
                return this.dbval.IsConnected()
            },
            EscapeString: (value) => {
                return this.dbval.EscapeString(value)
            },
            GetVersion: () => {
                return this.dbval.GetVersion()
            },
            QueryParams: (query, arguments, callback) => {
                if (typeof query != "string") query = String(query)
                if (typeof arguments != "object") arguments = {}

                let has_ats = query.includes("@")
                let has_brace = query.includes("{")
                let has_bracket = query.includes("[")

                for (const [k, v] in Object.entries(arguments)) {
                    let key = (typeof k == "string" ? k : String(k))
                    let value = this.EscapeString(v)

                    if (has_ats) query = query.replace(new RegExp("@" + key, "g"), value)
                    if (has_brace) query = query.replace(new RegExp("{" + key + "}", "g"), value)
                    if (has_bracket) query = query.replace(new RegExp("[" + key + "]", "g"), value)
                }

                this.Query(query, callback)
            },
            QueryBuilder: () => {
                let qbTable = self.dbval.QueryBuilder()
                if (!qbTable) return null
                return global[qbTable](this)
            }
        }
    }

}

LoadDatabase(globalThis)