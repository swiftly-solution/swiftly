#include "../../../core/scripting/generated/classes/GCEnvSplash.h"
#include "../core.h"

void SetupLuaClassGCEnvSplash(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSplash>("CEnvSplash")
        .addProperty("Scale", &GCEnvSplash::GetScale, &GCEnvSplash::SetScale)
        .endClass();
}