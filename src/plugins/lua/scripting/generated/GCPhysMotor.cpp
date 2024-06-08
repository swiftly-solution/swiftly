#include "../../../core/scripting/generated/classes/GCPhysMotor.h"
#include "../core.h"

void SetupLuaClassGCPhysMotor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysMotor>("CPhysMotor")
        .addProperty("NameAttach", &GCPhysMotor::GetNameAttach, &GCPhysMotor::SetNameAttach)
        .addProperty("AttachedObject", &GCPhysMotor::GetAttachedObject, &GCPhysMotor::SetAttachedObject)
        .addProperty("SpinUp", &GCPhysMotor::GetSpinUp, &GCPhysMotor::SetSpinUp)
        .addProperty("AdditionalAcceleration", &GCPhysMotor::GetAdditionalAcceleration, &GCPhysMotor::SetAdditionalAcceleration)
        .addProperty("AngularAcceleration", &GCPhysMotor::GetAngularAcceleration, &GCPhysMotor::SetAngularAcceleration)
        .addProperty("Motor", &GCPhysMotor::GetMotor, &GCPhysMotor::SetMotor)
        .endClass();
}