#include "../../../core/scripting/generated/classes/GC_CSGO_PreviewPlayer_GraphController.h"
#include "../core.h"

void SetupLuaClassGC_CSGO_PreviewPlayer_GraphController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_CSGO_PreviewPlayer_GraphController>("C_CSGO_PreviewPlayer_GraphController")

        .endClass();
}