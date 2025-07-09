local mem_terminateround = Memory()
mem_terminateround:LoadFromSignatureName("CGameRules_TerminateRound")
local hook_terminateround = AddHook(mem_terminateround, "pufuu", "v")

AddPreHookListener(hook_terminateround, function(p_Event)
    -- ...
end)
