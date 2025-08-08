using SwiftlyS2.API.Scripting;
// This will create a configuration at addons/swiftly/configs/plugins/configuration.json

Events.AddEventHandler("OnPluginStart", (Events.Event @e) => {
    var configData = new Dictonary<string, object>
    {
        ["test"] = "Test",
        ["test2"] = new Dictionary<string, object>
        {
            ["test3"] = "Test3"
        },
        ["test3"] = new int[] { 1, 3, 5, 10 }
    };

    Configuration.Create("configuration", configData);

    return EventResult.Continue;
});