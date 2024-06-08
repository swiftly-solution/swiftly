#include "../../../core/scripting/generated/classes/GCPlatTrigger.h"
#include "../core.h"

void SetupLuaClassGCPlatTrigger(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlatTrigger>("CPlatTrigger")
        .addProperty("Platform", &GCPlatTrigger::GetPlatform, &GCPlatTrigger::SetPlatform)
        .endClass();
}