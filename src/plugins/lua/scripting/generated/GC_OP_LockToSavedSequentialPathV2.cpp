#include "../../../core/scripting/generated/classes/GC_OP_LockToSavedSequentialPathV2.h"
#include "../core.h"

void SetupLuaClassGC_OP_LockToSavedSequentialPathV2(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LockToSavedSequentialPathV2>("C_OP_LockToSavedSequentialPathV2")
        .addProperty("FadeStart", &GC_OP_LockToSavedSequentialPathV2::GetFadeStart, &GC_OP_LockToSavedSequentialPathV2::SetFadeStart)
        .addProperty("FadeEnd", &GC_OP_LockToSavedSequentialPathV2::GetFadeEnd, &GC_OP_LockToSavedSequentialPathV2::SetFadeEnd)
        .addProperty("CPPairs", &GC_OP_LockToSavedSequentialPathV2::GetCPPairs, &GC_OP_LockToSavedSequentialPathV2::SetCPPairs)
        .addProperty("PathParams", &GC_OP_LockToSavedSequentialPathV2::GetPathParams, &GC_OP_LockToSavedSequentialPathV2::SetPathParams)
        .endClass();
}