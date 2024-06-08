#include "../../../core/scripting/generated/classes/GCPhysWheelConstraint.h"
#include "../core.h"

void SetupLuaClassGCPhysWheelConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysWheelConstraint>("CPhysWheelConstraint")
        .addProperty("SuspensionFrequency", &GCPhysWheelConstraint::GetSuspensionFrequency, &GCPhysWheelConstraint::SetSuspensionFrequency)
        .addProperty("SuspensionDampingRatio", &GCPhysWheelConstraint::GetSuspensionDampingRatio, &GCPhysWheelConstraint::SetSuspensionDampingRatio)
        .addProperty("SuspensionHeightOffset", &GCPhysWheelConstraint::GetSuspensionHeightOffset, &GCPhysWheelConstraint::SetSuspensionHeightOffset)
        .addProperty("EnableSuspensionLimit", &GCPhysWheelConstraint::GetEnableSuspensionLimit, &GCPhysWheelConstraint::SetEnableSuspensionLimit)
        .addProperty("MinSuspensionOffset", &GCPhysWheelConstraint::GetMinSuspensionOffset, &GCPhysWheelConstraint::SetMinSuspensionOffset)
        .addProperty("MaxSuspensionOffset", &GCPhysWheelConstraint::GetMaxSuspensionOffset, &GCPhysWheelConstraint::SetMaxSuspensionOffset)
        .addProperty("EnableSteeringLimit", &GCPhysWheelConstraint::GetEnableSteeringLimit, &GCPhysWheelConstraint::SetEnableSteeringLimit)
        .addProperty("MinSteeringAngle", &GCPhysWheelConstraint::GetMinSteeringAngle, &GCPhysWheelConstraint::SetMinSteeringAngle)
        .addProperty("MaxSteeringAngle", &GCPhysWheelConstraint::GetMaxSteeringAngle, &GCPhysWheelConstraint::SetMaxSteeringAngle)
        .addProperty("SteeringAxisFriction", &GCPhysWheelConstraint::GetSteeringAxisFriction, &GCPhysWheelConstraint::SetSteeringAxisFriction)
        .addProperty("SpinAxisFriction", &GCPhysWheelConstraint::GetSpinAxisFriction, &GCPhysWheelConstraint::SetSpinAxisFriction)
        .endClass();
}