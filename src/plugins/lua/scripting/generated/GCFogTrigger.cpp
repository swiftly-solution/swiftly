#include "../../../core/scripting/generated/classes/GCFogTrigger.h"
#include "../core.h"

void SetupLuaClassGCFogTrigger(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFogTrigger>("CFogTrigger")
        .addProperty("Fog", &GCFogTrigger::GetFog, &GCFogTrigger::SetFog)
        .endClass();
}