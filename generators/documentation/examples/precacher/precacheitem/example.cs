using SwiftlyS2.API.Scripting;

Events.AddEventHandler("OnPluginStart", (Events.Event @e) => {
    Precacher.PrecacheItem("characters/models/ctm_fbi/ctm_fbi.vmdl");
});