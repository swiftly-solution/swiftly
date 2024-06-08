#include "../../../core/scripting/generated/classes/GCPhysImpact.h"
#include "../core.h"

void SetupLuaClassGCPhysImpact(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysImpact>("CPhysImpact")
        .addProperty("Damage", &GCPhysImpact::GetDamage, &GCPhysImpact::SetDamage)
        .addProperty("Distance", &GCPhysImpact::GetDistance, &GCPhysImpact::SetDistance)
        .addProperty("DirectionEntityName", &GCPhysImpact::GetDirectionEntityName, &GCPhysImpact::SetDirectionEntityName)
        .endClass();
}