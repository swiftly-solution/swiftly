#include "../../../core/scripting/generated/classes/GCFootDefinition.h"
#include "../core.h"

void SetupLuaClassGCFootDefinition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootDefinition>("CFootDefinition")
        .addProperty("Name", &GCFootDefinition::GetName, &GCFootDefinition::SetName)
        .addProperty("AnkleBoneName", &GCFootDefinition::GetAnkleBoneName, &GCFootDefinition::SetAnkleBoneName)
        .addProperty("ToeBoneName", &GCFootDefinition::GetToeBoneName, &GCFootDefinition::SetToeBoneName)
        .addProperty("BallOffset", &GCFootDefinition::GetBallOffset, &GCFootDefinition::SetBallOffset)
        .addProperty("HeelOffset", &GCFootDefinition::GetHeelOffset, &GCFootDefinition::SetHeelOffset)
        .addProperty("FootLength", &GCFootDefinition::GetFootLength, &GCFootDefinition::SetFootLength)
        .addProperty("BindPoseDirectionMS", &GCFootDefinition::GetBindPoseDirectionMS, &GCFootDefinition::SetBindPoseDirectionMS)
        .addProperty("TraceHeight", &GCFootDefinition::GetTraceHeight, &GCFootDefinition::SetTraceHeight)
        .addProperty("TraceRadius", &GCFootDefinition::GetTraceRadius, &GCFootDefinition::SetTraceRadius)
        .endClass();
}