#include "../../../core/scripting/generated/classes/GC_OP_RepeatedTriggerChildGroup.h"
#include "../core.h"

void SetupLuaClassGC_OP_RepeatedTriggerChildGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RepeatedTriggerChildGroup>("C_OP_RepeatedTriggerChildGroup")
        .addProperty("ChildGroupID", &GC_OP_RepeatedTriggerChildGroup::GetChildGroupID, &GC_OP_RepeatedTriggerChildGroup::SetChildGroupID)
        .addProperty("ClusterRefireTime", &GC_OP_RepeatedTriggerChildGroup::GetClusterRefireTime, &GC_OP_RepeatedTriggerChildGroup::SetClusterRefireTime)
        .addProperty("ClusterSize", &GC_OP_RepeatedTriggerChildGroup::GetClusterSize, &GC_OP_RepeatedTriggerChildGroup::SetClusterSize)
        .addProperty("ClusterCooldown", &GC_OP_RepeatedTriggerChildGroup::GetClusterCooldown, &GC_OP_RepeatedTriggerChildGroup::SetClusterCooldown)
        .addProperty("LimitChildCount", &GC_OP_RepeatedTriggerChildGroup::GetLimitChildCount, &GC_OP_RepeatedTriggerChildGroup::SetLimitChildCount)
        .endClass();
}