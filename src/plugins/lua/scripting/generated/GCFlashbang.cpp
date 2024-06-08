#include "../../../core/scripting/generated/classes/GCFlashbang.h"
#include "../core.h"

void SetupLuaClassGCFlashbang(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlashbang>("CFlashbang")

        .endClass();
}