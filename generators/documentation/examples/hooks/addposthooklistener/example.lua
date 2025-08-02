local mem_terminateround = Memory()
mem_terminateround:LoadFromSignatureName("CGameRules_TerminateRound")
local hook_terminateround = AddHook(mem_terminateround, "pufuu", "v")

AddPostHookListener(hook_terminateround, function(p_Event)
    -- ...
end)
