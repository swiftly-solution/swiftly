#ifndef _memory_hooks_manager_h
#define _memory_hooks_manager_h

#include "vfunctions.h"
#include "functions.h"

#include <vector>

class HookManager
{
private:
    std::vector<FunctionHook*> funchookQueue;
    std::vector<VFunctionHook*> vfunchookQueue;
    bool initialized = false;
public:
    void Initialize();
    void Shutdown();

    void AddToQueue(FunctionHook* hook);
    void AddToQueue(VFunctionHook* hook);
};

extern HookManager g_hookManager;

#endif