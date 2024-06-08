#include "../../../core/scripting/generated/classes/GVPhysXBodyPart_t.h"
#include "../core.h"

void SetupLuaClassGVPhysXBodyPart_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXBodyPart_t>("VPhysXBodyPart_t")
        .addProperty("Flags", &GVPhysXBodyPart_t::GetFlags, &GVPhysXBodyPart_t::SetFlags)
        .addProperty("Mass", &GVPhysXBodyPart_t::GetMass, &GVPhysXBodyPart_t::SetMass)
        .addProperty("RnShape", &GVPhysXBodyPart_t::GetRnShape, &GVPhysXBodyPart_t::SetRnShape)
        .addProperty("CollisionAttributeIndex", &GVPhysXBodyPart_t::GetCollisionAttributeIndex, &GVPhysXBodyPart_t::SetCollisionAttributeIndex)
        .addProperty("Reserved", &GVPhysXBodyPart_t::GetReserved, &GVPhysXBodyPart_t::SetReserved)
        .addProperty("InertiaScale", &GVPhysXBodyPart_t::GetInertiaScale, &GVPhysXBodyPart_t::SetInertiaScale)
        .addProperty("LinearDamping", &GVPhysXBodyPart_t::GetLinearDamping, &GVPhysXBodyPart_t::SetLinearDamping)
        .addProperty("AngularDamping", &GVPhysXBodyPart_t::GetAngularDamping, &GVPhysXBodyPart_t::SetAngularDamping)
        .addProperty("OverrideMassCenter", &GVPhysXBodyPart_t::GetOverrideMassCenter, &GVPhysXBodyPart_t::SetOverrideMassCenter)
        .addProperty("MassCenterOverride", &GVPhysXBodyPart_t::GetMassCenterOverride, &GVPhysXBodyPart_t::SetMassCenterOverride)
        .endClass();
}