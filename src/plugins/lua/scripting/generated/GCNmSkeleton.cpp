#include "../../../core/scripting/generated/classes/GCNmSkeleton.h"
#include "../core.h"

void SetupLuaClassGCNmSkeleton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmSkeleton>("CNmSkeleton")
        .addProperty("ParentIndices", &GCNmSkeleton::GetParentIndices, &GCNmSkeleton::SetParentIndices)
        .addProperty("NumBonesToSampleAtLowLOD", &GCNmSkeleton::GetNumBonesToSampleAtLowLOD, &GCNmSkeleton::SetNumBonesToSampleAtLowLOD)
        .endClass();
}