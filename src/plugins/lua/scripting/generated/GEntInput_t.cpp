#include "../../../core/scripting/generated/classes/GEntInput_t.h"
#include "../core.h"

void SetupLuaClassGEntInput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntInput_t>("EntInput_t")

        .endClass();
}