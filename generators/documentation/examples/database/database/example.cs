using SwiftlyS2.API.Scripting;
using System.Text.Json;

Events.AddEventHandler("OnPluginStart", (Events.Event @e) => {
    var db = new Database("CONNECTION_NAME");

    if (!db.IsConnected()) return EventResult.Continue;
    db.Query("select * from users", (err, result) => {
        if(err) return Console.WriteLine(err);

        for(var i = 0; i < result.Length; i++)
        {      
            Console.WriteLine($"Row {i}: {JsonSerializer.Serialize(result[i])}");
        }
    });
    return EventResult.Continue;
})