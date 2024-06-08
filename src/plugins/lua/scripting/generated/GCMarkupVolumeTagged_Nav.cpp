#include "../../../core/scripting/generated/classes/GCMarkupVolumeTagged_Nav.h"
#include "../core.h"

void SetupLuaClassGCMarkupVolumeTagged_Nav(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMarkupVolumeTagged_Nav>("CMarkupVolumeTagged_Nav")

        .endClass();
}