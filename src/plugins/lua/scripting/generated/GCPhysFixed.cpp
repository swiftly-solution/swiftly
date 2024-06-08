#include "../../../core/scripting/generated/classes/GCPhysFixed.h"
#include "../core.h"

void SetupLuaClassGCPhysFixed(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysFixed>("CPhysFixed")
        .addProperty("LinearFrequency", &GCPhysFixed::GetLinearFrequency, &GCPhysFixed::SetLinearFrequency)
        .addProperty("LinearDampingRatio", &GCPhysFixed::GetLinearDampingRatio, &GCPhysFixed::SetLinearDampingRatio)
        .addProperty("AngularFrequency", &GCPhysFixed::GetAngularFrequency, &GCPhysFixed::SetAngularFrequency)
        .addProperty("AngularDampingRatio", &GCPhysFixed::GetAngularDampingRatio, &GCPhysFixed::SetAngularDampingRatio)
        .addProperty("EnableLinearConstraint", &GCPhysFixed::GetEnableLinearConstraint, &GCPhysFixed::SetEnableLinearConstraint)
        .addProperty("EnableAngularConstraint", &GCPhysFixed::GetEnableAngularConstraint, &GCPhysFixed::SetEnableAngularConstraint)
        .endClass();
}