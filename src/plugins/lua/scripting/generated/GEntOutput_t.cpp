#include "../../../core/scripting/generated/classes/GEntOutput_t.h"
#include "../core.h"

void SetupLuaClassGEntOutput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntOutput_t>("EntOutput_t")

        .endClass();
}