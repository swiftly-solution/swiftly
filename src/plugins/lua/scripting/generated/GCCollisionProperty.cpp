#include "../../../core/scripting/generated/classes/GCCollisionProperty.h"
#include "../core.h"

void SetupLuaClassGCCollisionProperty(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCollisionProperty>("CCollisionProperty")
        .addProperty("CollisionAttribute", &GCCollisionProperty::GetCollisionAttribute, &GCCollisionProperty::SetCollisionAttribute)
        .addProperty("Mins", &GCCollisionProperty::GetMins, &GCCollisionProperty::SetMins)
        .addProperty("Maxs", &GCCollisionProperty::GetMaxs, &GCCollisionProperty::SetMaxs)
        .addProperty("SolidFlags", &GCCollisionProperty::GetSolidFlags, &GCCollisionProperty::SetSolidFlags)
        .addProperty("SolidType", &GCCollisionProperty::GetSolidType, &GCCollisionProperty::SetSolidType)
        .addProperty("TriggerBloat", &GCCollisionProperty::GetTriggerBloat, &GCCollisionProperty::SetTriggerBloat)
        .addProperty("SurroundType", &GCCollisionProperty::GetSurroundType, &GCCollisionProperty::SetSurroundType)
        .addProperty("CollisionGroup", &GCCollisionProperty::GetCollisionGroup, &GCCollisionProperty::SetCollisionGroup)
        .addProperty("EnablePhysics", &GCCollisionProperty::GetEnablePhysics, &GCCollisionProperty::SetEnablePhysics)
        .addProperty("BoundingRadius", &GCCollisionProperty::GetBoundingRadius, &GCCollisionProperty::SetBoundingRadius)
        .addProperty("SpecifiedSurroundingMins", &GCCollisionProperty::GetSpecifiedSurroundingMins, &GCCollisionProperty::SetSpecifiedSurroundingMins)
        .addProperty("SpecifiedSurroundingMaxs", &GCCollisionProperty::GetSpecifiedSurroundingMaxs, &GCCollisionProperty::SetSpecifiedSurroundingMaxs)
        .addProperty("SurroundingMaxs", &GCCollisionProperty::GetSurroundingMaxs, &GCCollisionProperty::SetSurroundingMaxs)
        .addProperty("SurroundingMins", &GCCollisionProperty::GetSurroundingMins, &GCCollisionProperty::SetSurroundingMins)
        .addProperty("CapsuleCenter1", &GCCollisionProperty::GetCapsuleCenter1, &GCCollisionProperty::SetCapsuleCenter1)
        .addProperty("CapsuleCenter2", &GCCollisionProperty::GetCapsuleCenter2, &GCCollisionProperty::SetCapsuleCenter2)
        .addProperty("CapsuleRadius", &GCCollisionProperty::GetCapsuleRadius, &GCCollisionProperty::SetCapsuleRadius)
        .endClass();
}