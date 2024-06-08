#include "../../../core/scripting/generated/classes/GVPhysXJoint_t.h"
#include "../core.h"

void SetupLuaClassGVPhysXJoint_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXJoint_t>("VPhysXJoint_t")
        .addProperty("Type", &GVPhysXJoint_t::GetType, &GVPhysXJoint_t::SetType)
        .addProperty("Body1", &GVPhysXJoint_t::GetBody1, &GVPhysXJoint_t::SetBody1)
        .addProperty("Body2", &GVPhysXJoint_t::GetBody2, &GVPhysXJoint_t::SetBody2)
        .addProperty("Flags", &GVPhysXJoint_t::GetFlags, &GVPhysXJoint_t::SetFlags)
        .addProperty("EnableCollision", &GVPhysXJoint_t::GetEnableCollision, &GVPhysXJoint_t::SetEnableCollision)
        .addProperty("EnableLinearLimit", &GVPhysXJoint_t::GetEnableLinearLimit, &GVPhysXJoint_t::SetEnableLinearLimit)
        .addProperty("LinearLimit", &GVPhysXJoint_t::GetLinearLimit, &GVPhysXJoint_t::SetLinearLimit)
        .addProperty("EnableLinearMotor", &GVPhysXJoint_t::GetEnableLinearMotor, &GVPhysXJoint_t::SetEnableLinearMotor)
        .addProperty("LinearTargetVelocity", &GVPhysXJoint_t::GetLinearTargetVelocity, &GVPhysXJoint_t::SetLinearTargetVelocity)
        .addProperty("MaxForce", &GVPhysXJoint_t::GetMaxForce, &GVPhysXJoint_t::SetMaxForce)
        .addProperty("EnableSwingLimit", &GVPhysXJoint_t::GetEnableSwingLimit, &GVPhysXJoint_t::SetEnableSwingLimit)
        .addProperty("SwingLimit", &GVPhysXJoint_t::GetSwingLimit, &GVPhysXJoint_t::SetSwingLimit)
        .addProperty("EnableTwistLimit", &GVPhysXJoint_t::GetEnableTwistLimit, &GVPhysXJoint_t::SetEnableTwistLimit)
        .addProperty("TwistLimit", &GVPhysXJoint_t::GetTwistLimit, &GVPhysXJoint_t::SetTwistLimit)
        .addProperty("EnableAngularMotor", &GVPhysXJoint_t::GetEnableAngularMotor, &GVPhysXJoint_t::SetEnableAngularMotor)
        .addProperty("AngularTargetVelocity", &GVPhysXJoint_t::GetAngularTargetVelocity, &GVPhysXJoint_t::SetAngularTargetVelocity)
        .addProperty("MaxTorque", &GVPhysXJoint_t::GetMaxTorque, &GVPhysXJoint_t::SetMaxTorque)
        .addProperty("LinearFrequency", &GVPhysXJoint_t::GetLinearFrequency, &GVPhysXJoint_t::SetLinearFrequency)
        .addProperty("LinearDampingRatio", &GVPhysXJoint_t::GetLinearDampingRatio, &GVPhysXJoint_t::SetLinearDampingRatio)
        .addProperty("AngularFrequency", &GVPhysXJoint_t::GetAngularFrequency, &GVPhysXJoint_t::SetAngularFrequency)
        .addProperty("AngularDampingRatio", &GVPhysXJoint_t::GetAngularDampingRatio, &GVPhysXJoint_t::SetAngularDampingRatio)
        .addProperty("Friction", &GVPhysXJoint_t::GetFriction, &GVPhysXJoint_t::SetFriction)
        .endClass();
}