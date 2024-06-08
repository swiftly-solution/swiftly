#include "../../../core/scripting/generated/classes/GCCachedPose.h"
#include "../core.h"

void SetupLuaClassGCCachedPose(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCachedPose>("CCachedPose")
        .addProperty("MorphWeights", &GCCachedPose::GetMorphWeights, &GCCachedPose::SetMorphWeights)
        .addProperty("Cycle", &GCCachedPose::GetCycle, &GCCachedPose::SetCycle)
        .endClass();
}