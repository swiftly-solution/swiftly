#include "../../../core/scripting/generated/classes/GC_OP_LockToSavedSequentialPath.h"
#include "../core.h"

void SetupLuaClassGC_OP_LockToSavedSequentialPath(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LockToSavedSequentialPath>("C_OP_LockToSavedSequentialPath")
        .addProperty("FadeStart", &GC_OP_LockToSavedSequentialPath::GetFadeStart, &GC_OP_LockToSavedSequentialPath::SetFadeStart)
        .addProperty("FadeEnd", &GC_OP_LockToSavedSequentialPath::GetFadeEnd, &GC_OP_LockToSavedSequentialPath::SetFadeEnd)
        .addProperty("CPPairs", &GC_OP_LockToSavedSequentialPath::GetCPPairs, &GC_OP_LockToSavedSequentialPath::SetCPPairs)
        .addProperty("PathParams", &GC_OP_LockToSavedSequentialPath::GetPathParams, &GC_OP_LockToSavedSequentialPath::SetPathParams)
        .endClass();
}