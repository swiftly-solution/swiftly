#include "../../../core/scripting/generated/classes/GCMultiplayer_Expresser.h"
#include "../core.h"

void SetupLuaClassGCMultiplayer_Expresser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMultiplayer_Expresser>("CMultiplayer_Expresser")
        .addProperty("AllowMultipleScenes", &GCMultiplayer_Expresser::GetAllowMultipleScenes, &GCMultiplayer_Expresser::SetAllowMultipleScenes)
        .endClass();
}