#include "../../../core/scripting/generated/classes/GCPhysSlideConstraint.h"
#include "../core.h"

void SetupLuaClassGCPhysSlideConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysSlideConstraint>("CPhysSlideConstraint")
        .addProperty("AxisEnd", &GCPhysSlideConstraint::GetAxisEnd, &GCPhysSlideConstraint::SetAxisEnd)
        .addProperty("SlideFriction", &GCPhysSlideConstraint::GetSlideFriction, &GCPhysSlideConstraint::SetSlideFriction)
        .addProperty("SystemLoadScale", &GCPhysSlideConstraint::GetSystemLoadScale, &GCPhysSlideConstraint::SetSystemLoadScale)
        .addProperty("InitialOffset", &GCPhysSlideConstraint::GetInitialOffset, &GCPhysSlideConstraint::SetInitialOffset)
        .addProperty("EnableLinearConstraint", &GCPhysSlideConstraint::GetEnableLinearConstraint, &GCPhysSlideConstraint::SetEnableLinearConstraint)
        .addProperty("EnableAngularConstraint", &GCPhysSlideConstraint::GetEnableAngularConstraint, &GCPhysSlideConstraint::SetEnableAngularConstraint)
        .addProperty("MotorFrequency", &GCPhysSlideConstraint::GetMotorFrequency, &GCPhysSlideConstraint::SetMotorFrequency)
        .addProperty("MotorDampingRatio", &GCPhysSlideConstraint::GetMotorDampingRatio, &GCPhysSlideConstraint::SetMotorDampingRatio)
        .addProperty("UseEntityPivot", &GCPhysSlideConstraint::GetUseEntityPivot, &GCPhysSlideConstraint::SetUseEntityPivot)
        .addProperty("SoundInfo", &GCPhysSlideConstraint::GetSoundInfo, &GCPhysSlideConstraint::SetSoundInfo)
        .endClass();
}