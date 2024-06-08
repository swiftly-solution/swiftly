#include "../../../core/scripting/generated/classes/GCFootTrajectory.h"
#include "../core.h"

void SetupLuaClassGCFootTrajectory(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootTrajectory>("CFootTrajectory")
        .addProperty("Offset", &GCFootTrajectory::GetOffset, &GCFootTrajectory::SetOffset)
        .addProperty("RotationOffset", &GCFootTrajectory::GetRotationOffset, &GCFootTrajectory::SetRotationOffset)
        .addProperty("Progression", &GCFootTrajectory::GetProgression, &GCFootTrajectory::SetProgression)
        .endClass();
}