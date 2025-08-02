AddEventHandler("OnPluginStart", (event) => {
    db = Database("CONNECTION_NAME")

    if (!db.IsConnected()) return;

    db.QueryBuilder().Table("users").Create({
        steamid: "string|max:128|unique",
        name: "string"
    }).Execute()

    return EventResult.Continue
})
