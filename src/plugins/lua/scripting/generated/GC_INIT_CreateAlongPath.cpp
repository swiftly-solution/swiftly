#include "../../../core/scripting/generated/classes/GC_INIT_CreateAlongPath.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateAlongPath(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateAlongPath>("C_INIT_CreateAlongPath")
        .addProperty("MaxDistance", &GC_INIT_CreateAlongPath::GetMaxDistance, &GC_INIT_CreateAlongPath::SetMaxDistance)
        .addProperty("PathParams", &GC_INIT_CreateAlongPath::GetPathParams, &GC_INIT_CreateAlongPath::SetPathParams)
        .addProperty("UseRandomCPs", &GC_INIT_CreateAlongPath::GetUseRandomCPs, &GC_INIT_CreateAlongPath::SetUseRandomCPs)
        .addProperty("EndOffset", &GC_INIT_CreateAlongPath::GetEndOffset, &GC_INIT_CreateAlongPath::SetEndOffset)
        .addProperty("SaveOffset", &GC_INIT_CreateAlongPath::GetSaveOffset, &GC_INIT_CreateAlongPath::SetSaveOffset)
        .endClass();
}