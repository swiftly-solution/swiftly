using SwiftlyS2.API.Scripting;

var mem_terminateround = new Memory();
mem_terminateround.LoadFromSignatureName("CGameRules_TerminateRound");
var hook_terminateround = Hooks.AddHook(mem_terminateround, "pufuu", "v");

Hooks.CallHook(hook_terminateround, Generic.GetCCSGameRules(), 1, 5.0, 1, 1)