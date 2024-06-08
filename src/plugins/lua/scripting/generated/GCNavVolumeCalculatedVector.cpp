#include "../../../core/scripting/generated/classes/GCNavVolumeCalculatedVector.h"
#include "../core.h"

void SetupLuaClassGCNavVolumeCalculatedVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeCalculatedVector>("CNavVolumeCalculatedVector")

        .endClass();
}