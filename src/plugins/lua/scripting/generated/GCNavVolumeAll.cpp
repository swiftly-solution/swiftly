#include "../../../core/scripting/generated/classes/GCNavVolumeAll.h"
#include "../core.h"

void SetupLuaClassGCNavVolumeAll(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeAll>("CNavVolumeAll")

        .endClass();
}