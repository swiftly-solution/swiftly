#include "../scripting.h"
#include "../../../sdk/entity/CGameRules.h"
#include "../../../hooks/FuncHook.h"
#include "generated/classes.h"

void Hook_CGameRules_Constructor(CGameRules *pThis);
CCSGameRules *gameRules = nullptr;
GCCSGameRules *gameRulesPtr = nullptr;

FuncHook<decltype(Hook_CGameRules_Constructor)> CGameRules_ConstructorT(Hook_CGameRules_Constructor, "CGameRules_Constructor");

void Hook_CGameRules_Constructor(CGameRules *pThis)
{
    gameRules = (CCSGameRules *)pThis;
    CGameRules_ConstructorT(pThis);
}

bool scripting_IsWindows()
{
    return WIN_LINUX(true, false);
}

bool scripting_IsLinux()
{
    return WIN_LINUX(false, true);
}

std::string scripting_GetOS()
{
    return WIN_LINUX("Windows", "Linux");
}

GCCSGameRules *scripting_GetCCSGameRules()
{
    if (!gameRulesPtr)
        gameRulesPtr = new GCCSGameRules((void *)gameRules);
    else if (gameRulesPtr->GetPtr() != (void *)gameRules)
    {
        delete gameRulesPtr;
        gameRulesPtr = new GCCSGameRules((void *)gameRules);
    }

    return gameRulesPtr;
}