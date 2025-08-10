-- This will create a configuration at addons/swiftly/configs/plugins/configuration.json
AddEventHandler("OnPluginStart", function(event)
    config:Create("configuration", {
        test = "Test",
        test2 = {
            test3 = "Test3"
        },
        test3 = { 1, 3, 5, 10 }
    })
    return EventResult.Continue
end)
