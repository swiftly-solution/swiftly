#include "../../../core/scripting/generated/classes/GCEnvWind.h"
#include "../core.h"

void SetupLuaClassGCEnvWind(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvWind>("CEnvWind")
        .addProperty("EnvWindShared", &GCEnvWind::GetEnvWindShared, &GCEnvWind::SetEnvWindShared)
        .endClass();
}