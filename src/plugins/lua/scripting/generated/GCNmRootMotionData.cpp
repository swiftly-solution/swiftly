#include "../../../core/scripting/generated/classes/GCNmRootMotionData.h"
#include "../core.h"

void SetupLuaClassGCNmRootMotionData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmRootMotionData>("CNmRootMotionData")
        .addProperty("NumFrames", &GCNmRootMotionData::GetNumFrames, &GCNmRootMotionData::SetNumFrames)
        .addProperty("AverageLinearVelocity", &GCNmRootMotionData::GetAverageLinearVelocity, &GCNmRootMotionData::SetAverageLinearVelocity)
        .addProperty("AverageAngularVelocityRadians", &GCNmRootMotionData::GetAverageAngularVelocityRadians, &GCNmRootMotionData::SetAverageAngularVelocityRadians)
        .endClass();
}