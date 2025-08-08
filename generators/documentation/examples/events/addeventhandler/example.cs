using SwiftlyS2.API.Scripting;

Events.AddEventHandler("OnPluginStart", (Events.Event @e) => {
    Console.WriteLine("Plugin Started");
});