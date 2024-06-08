#include "../../../core/scripting/generated/classes/GEventSplitScreenStateChanged_t.h"
#include "../core.h"

void SetupLuaClassGEventSplitScreenStateChanged_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventSplitScreenStateChanged_t>("EventSplitScreenStateChanged_t")

        .endClass();
}