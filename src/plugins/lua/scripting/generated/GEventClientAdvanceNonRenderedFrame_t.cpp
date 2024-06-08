#include "../../../core/scripting/generated/classes/GEventClientAdvanceNonRenderedFrame_t.h"
#include "../core.h"

void SetupLuaClassGEventClientAdvanceNonRenderedFrame_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientAdvanceNonRenderedFrame_t>("EventClientAdvanceNonRenderedFrame_t")

        .endClass();
}