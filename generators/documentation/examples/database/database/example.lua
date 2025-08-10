AddEventHandler("OnPluginStart", function(event)
    db = Database("CONNECTION_NAME")

    if not db:IsConnected() then return end
    db:Query("select * from users", function(err, result)
        if err then return print(err) end

        for i = 1, #result do
            print("Row " .. i .. ": " .. json.encode(result[i]))
        end
    end)

    return EventResult.Continue
end)
