#include "../../../core/scripting/generated/classes/GCFootStride.h"
#include "../core.h"

void SetupLuaClassGCFootStride(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootStride>("CFootStride")
        .addProperty("Definition", &GCFootStride::GetDefinition, &GCFootStride::SetDefinition)
        .addProperty("Trajectories", &GCFootStride::GetTrajectories, &GCFootStride::SetTrajectories)
        .endClass();
}