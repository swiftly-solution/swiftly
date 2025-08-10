using SwiftlyS2.API.Scripting;

Events.AddEventHandler("OnPluginStart", (Events.Event @e) => {
    var db = new Database("CONNECTION_NAME");

    if (!db.IsConnected()) return EventResult.Continue;

    db.QueryBuilder()
      .Table("users")
      .Create(new Dictionary<string, string>
      {
          ["steamid"] = "string|max:128|unique",
          ["name"] = "string"
      })
      .Execute();

    return EventResult.Continue;
});