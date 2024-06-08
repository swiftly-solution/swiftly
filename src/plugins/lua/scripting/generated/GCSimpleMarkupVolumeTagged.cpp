#include "../../../core/scripting/generated/classes/GCSimpleMarkupVolumeTagged.h"
#include "../core.h"

void SetupLuaClassGCSimpleMarkupVolumeTagged(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSimpleMarkupVolumeTagged>("CSimpleMarkupVolumeTagged")

        .endClass();
}