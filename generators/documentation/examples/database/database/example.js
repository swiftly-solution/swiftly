AddEventHandler("OnPluginStart", (event) => {
    db = Database("CONNECTION_NAME")

    if (!db.IsConnected()) return;
    db.Query("select * from users", (err, result) => {
        if (err) return console.log(err);

        for (let i = 0; i < result.length; i++) {
            console.log(`Row ${i + 1}: ${JSON.stringify(result[i])}`)
        }
    })

    return EventResult.Continue
})
