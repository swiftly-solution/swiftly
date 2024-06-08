#include "../../../core/scripting/generated/classes/GC_INIT_CreateSequentialPath.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateSequentialPath(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateSequentialPath>("C_INIT_CreateSequentialPath")
        .addProperty("MaxDistance", &GC_INIT_CreateSequentialPath::GetMaxDistance, &GC_INIT_CreateSequentialPath::SetMaxDistance)
        .addProperty("NumToAssign", &GC_INIT_CreateSequentialPath::GetNumToAssign, &GC_INIT_CreateSequentialPath::SetNumToAssign)
        .addProperty("Loop", &GC_INIT_CreateSequentialPath::GetLoop, &GC_INIT_CreateSequentialPath::SetLoop)
        .addProperty("CPPairs", &GC_INIT_CreateSequentialPath::GetCPPairs, &GC_INIT_CreateSequentialPath::SetCPPairs)
        .addProperty("SaveOffset", &GC_INIT_CreateSequentialPath::GetSaveOffset, &GC_INIT_CreateSequentialPath::SetSaveOffset)
        .addProperty("PathParams", &GC_INIT_CreateSequentialPath::GetPathParams, &GC_INIT_CreateSequentialPath::SetPathParams)
        .endClass();
}