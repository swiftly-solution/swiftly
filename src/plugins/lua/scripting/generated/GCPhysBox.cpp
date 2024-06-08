#include "../../../core/scripting/generated/classes/GCPhysBox.h"
#include "../core.h"

void SetupLuaClassGCPhysBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysBox>("CPhysBox")
        .addProperty("DamageType", &GCPhysBox::GetDamageType, &GCPhysBox::SetDamageType)
        .addProperty("MassScale", &GCPhysBox::GetMassScale, &GCPhysBox::SetMassScale)
        .addProperty("DamageToEnableMotion", &GCPhysBox::GetDamageToEnableMotion, &GCPhysBox::SetDamageToEnableMotion)
        .addProperty("ForceToEnableMotion", &GCPhysBox::GetForceToEnableMotion, &GCPhysBox::SetForceToEnableMotion)
        .addProperty("PreferredCarryAngles", &GCPhysBox::GetPreferredCarryAngles, &GCPhysBox::SetPreferredCarryAngles)
        .addProperty("NotSolidToWorld", &GCPhysBox::GetNotSolidToWorld, &GCPhysBox::SetNotSolidToWorld)
        .addProperty("EnableUseOutput", &GCPhysBox::GetEnableUseOutput, &GCPhysBox::SetEnableUseOutput)
        .addProperty("ExploitableByPlayer", &GCPhysBox::GetExploitableByPlayer, &GCPhysBox::SetExploitableByPlayer)
        .addProperty("TouchOutputPerEntityDelay", &GCPhysBox::GetTouchOutputPerEntityDelay, &GCPhysBox::SetTouchOutputPerEntityDelay)
        .addProperty("OnDamaged", &GCPhysBox::GetOnDamaged, &GCPhysBox::SetOnDamaged)
        .addProperty("OnAwakened", &GCPhysBox::GetOnAwakened, &GCPhysBox::SetOnAwakened)
        .addProperty("OnMotionEnabled", &GCPhysBox::GetOnMotionEnabled, &GCPhysBox::SetOnMotionEnabled)
        .addProperty("OnPlayerUse", &GCPhysBox::GetOnPlayerUse, &GCPhysBox::SetOnPlayerUse)
        .addProperty("OnStartTouch", &GCPhysBox::GetOnStartTouch, &GCPhysBox::SetOnStartTouch)
        .addProperty("CarryingPlayer", &GCPhysBox::GetCarryingPlayer, &GCPhysBox::SetCarryingPlayer)
        .endClass();
}