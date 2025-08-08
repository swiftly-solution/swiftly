using SwiftlyS2.API.Scripting;

var mem_terminateround = new Memory();
mem_terminateround.LoadFromSignatureName("CGameRules_TerminateRound");
var hook_terminateround = Hooks.AddHook(mem_terminateround, "pufuu", "v");
