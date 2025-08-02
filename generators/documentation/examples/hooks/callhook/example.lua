local mem_terminateround = Memory()
mem_terminateround:LoadFromSignatureName("CGameRules_TerminateRound")
local hook_terminateround = AddHook(mem_terminateround, "pufuu", "v")

CallHook(hook_terminateround, GetCCSGameRules(), 1, 5.0, 1, 1)
