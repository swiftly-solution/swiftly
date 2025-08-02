AddEventHandler("OnPluginStart", function(event)
    db = Database("CONNECTION_NAME")

    if not db:IsConnected() then return end

    db:QueryBuilder():Table("users"):Create({
        steamid = "string|max:128|unique",
        name = "string"
    }):Execute()

    return EventResult.Continue
end)
