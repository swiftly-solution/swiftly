#include "../../../core/scripting/generated/classes/GCPropDataComponent.h"
#include "../core.h"

void SetupLuaClassGCPropDataComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPropDataComponent>("CPropDataComponent")
        .addProperty("DmgModBullet", &GCPropDataComponent::GetDmgModBullet, &GCPropDataComponent::SetDmgModBullet)
        .addProperty("DmgModClub", &GCPropDataComponent::GetDmgModClub, &GCPropDataComponent::SetDmgModClub)
        .addProperty("DmgModExplosive", &GCPropDataComponent::GetDmgModExplosive, &GCPropDataComponent::SetDmgModExplosive)
        .addProperty("DmgModFire", &GCPropDataComponent::GetDmgModFire, &GCPropDataComponent::SetDmgModFire)
        .addProperty("PhysicsDamageTableName", &GCPropDataComponent::GetPhysicsDamageTableName, &GCPropDataComponent::SetPhysicsDamageTableName)
        .addProperty("BasePropData", &GCPropDataComponent::GetBasePropData, &GCPropDataComponent::SetBasePropData)
        .addProperty("Interactions", &GCPropDataComponent::GetInteractions, &GCPropDataComponent::SetInteractions)
        .addProperty("SpawnMotionDisabled", &GCPropDataComponent::GetSpawnMotionDisabled, &GCPropDataComponent::SetSpawnMotionDisabled)
        .addProperty("DisableTakePhysicsDamageSpawnFlag", &GCPropDataComponent::GetDisableTakePhysicsDamageSpawnFlag, &GCPropDataComponent::SetDisableTakePhysicsDamageSpawnFlag)
        .addProperty("MotionDisabledSpawnFlag", &GCPropDataComponent::GetMotionDisabledSpawnFlag, &GCPropDataComponent::SetMotionDisabledSpawnFlag)
        .endClass();
}