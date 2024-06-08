#include "../../../core/scripting/generated/classes/GC_CSGO_PreviewModel_GraphController.h"
#include "../core.h"

void SetupLuaClassGC_CSGO_PreviewModel_GraphController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_CSGO_PreviewModel_GraphController>("C_CSGO_PreviewModel_GraphController")

        .endClass();
}