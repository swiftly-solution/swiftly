#include "../../../core/scripting/generated/classes/GCPointHurt.h"
#include "../core.h"

void SetupLuaClassGCPointHurt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointHurt>("CPointHurt")
        .addProperty("Damage", &GCPointHurt::GetDamage, &GCPointHurt::SetDamage)
        .addProperty("BitsDamageType", &GCPointHurt::GetBitsDamageType, &GCPointHurt::SetBitsDamageType)
        .addProperty("Radius", &GCPointHurt::GetRadius, &GCPointHurt::SetRadius)
        .addProperty("Delay", &GCPointHurt::GetDelay, &GCPointHurt::SetDelay)
        .addProperty("StrTarget", &GCPointHurt::GetStrTarget, &GCPointHurt::SetStrTarget)
        .addProperty("Activator", &GCPointHurt::GetActivator, &GCPointHurt::SetActivator)
        .endClass();
}