#include "../../../core/scripting/generated/classes/GCNavVolumeMarkupVolume.h"
#include "../core.h"

void SetupLuaClassGCNavVolumeMarkupVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeMarkupVolume>("CNavVolumeMarkupVolume")

        .endClass();
}