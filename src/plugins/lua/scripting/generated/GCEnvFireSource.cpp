#include "../../../core/scripting/generated/classes/GCEnvFireSource.h"
#include "../core.h"

void SetupLuaClassGCEnvFireSource(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvFireSource>("CEnvFireSource")
        .addProperty("Enabled", &GCEnvFireSource::GetEnabled, &GCEnvFireSource::SetEnabled)
        .addProperty("Radius", &GCEnvFireSource::GetRadius, &GCEnvFireSource::SetRadius)
        .addProperty("Damage", &GCEnvFireSource::GetDamage, &GCEnvFireSource::SetDamage)
        .endClass();
}