#include "../../../core/scripting/generated/classes/GCSymbolAnimParameter.h"
#include "../core.h"

void SetupLuaClassGCSymbolAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSymbolAnimParameter>("CSymbolAnimParameter")

        .endClass();
}