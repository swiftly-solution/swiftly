#include "../../../core/scripting/generated/classes/GC_INIT_CreateSequentialPathV2.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateSequentialPathV2(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateSequentialPathV2>("C_INIT_CreateSequentialPathV2")
        .addProperty("MaxDistance", &GC_INIT_CreateSequentialPathV2::GetMaxDistance, &GC_INIT_CreateSequentialPathV2::SetMaxDistance)
        .addProperty("NumToAssign", &GC_INIT_CreateSequentialPathV2::GetNumToAssign, &GC_INIT_CreateSequentialPathV2::SetNumToAssign)
        .addProperty("Loop", &GC_INIT_CreateSequentialPathV2::GetLoop, &GC_INIT_CreateSequentialPathV2::SetLoop)
        .addProperty("CPPairs", &GC_INIT_CreateSequentialPathV2::GetCPPairs, &GC_INIT_CreateSequentialPathV2::SetCPPairs)
        .addProperty("SaveOffset", &GC_INIT_CreateSequentialPathV2::GetSaveOffset, &GC_INIT_CreateSequentialPathV2::SetSaveOffset)
        .addProperty("PathParams", &GC_INIT_CreateSequentialPathV2::GetPathParams, &GC_INIT_CreateSequentialPathV2::SetPathParams)
        .endClass();
}