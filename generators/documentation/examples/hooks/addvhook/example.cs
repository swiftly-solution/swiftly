using SwiftlyS2.API.Scripting;

var hook_query = Hooks.AddVHook("engine2", "CServerSideClient", "CServerSideClient_OnConVarQuery", "pp", "b");
