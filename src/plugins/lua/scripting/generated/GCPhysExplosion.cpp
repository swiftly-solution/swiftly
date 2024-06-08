#include "../../../core/scripting/generated/classes/GCPhysExplosion.h"
#include "../core.h"

void SetupLuaClassGCPhysExplosion(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysExplosion>("CPhysExplosion")
        .addProperty("ExplodeOnSpawn", &GCPhysExplosion::GetExplodeOnSpawn, &GCPhysExplosion::SetExplodeOnSpawn)
        .addProperty("Magnitude", &GCPhysExplosion::GetMagnitude, &GCPhysExplosion::SetMagnitude)
        .addProperty("Damage", &GCPhysExplosion::GetDamage, &GCPhysExplosion::SetDamage)
        .addProperty("Radius", &GCPhysExplosion::GetRadius, &GCPhysExplosion::SetRadius)
        .addProperty("TargetEntityName", &GCPhysExplosion::GetTargetEntityName, &GCPhysExplosion::SetTargetEntityName)
        .addProperty("InnerRadius", &GCPhysExplosion::GetInnerRadius, &GCPhysExplosion::SetInnerRadius)
        .addProperty("PushScale", &GCPhysExplosion::GetPushScale, &GCPhysExplosion::SetPushScale)
        .addProperty("ConvertToDebrisWhenPossible", &GCPhysExplosion::GetConvertToDebrisWhenPossible, &GCPhysExplosion::SetConvertToDebrisWhenPossible)
        .addProperty("OnPushedPlayer", &GCPhysExplosion::GetOnPushedPlayer, &GCPhysExplosion::SetOnPushedPlayer)
        .endClass();
}