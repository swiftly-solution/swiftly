let mem_terminateround = Memory()
mem_terminateround.LoadFromSignatureName("CGameRules_TerminateRound")
let hook_terminateround = AddHook(mem_terminateround, "pufuu", "v")

AddPreHookListener(hook_terminateround, (p_Event) => {
    // ...
})
