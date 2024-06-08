#include "../../../core/scripting/generated/classes/GCItemKevlar.h"
#include "../core.h"

void SetupLuaClassGCItemKevlar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemKevlar>("CItemKevlar")

        .endClass();
}