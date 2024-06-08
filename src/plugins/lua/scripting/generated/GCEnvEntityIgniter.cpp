#include "../../../core/scripting/generated/classes/GCEnvEntityIgniter.h"
#include "../core.h"

void SetupLuaClassGCEnvEntityIgniter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvEntityIgniter>("CEnvEntityIgniter")
        .addProperty("Lifetime", &GCEnvEntityIgniter::GetLifetime, &GCEnvEntityIgniter::SetLifetime)
        .endClass();
}