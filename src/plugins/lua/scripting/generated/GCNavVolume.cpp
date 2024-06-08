#include "../../../core/scripting/generated/classes/GCNavVolume.h"
#include "../core.h"

void SetupLuaClassGCNavVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolume>("CNavVolume")

        .endClass();
}