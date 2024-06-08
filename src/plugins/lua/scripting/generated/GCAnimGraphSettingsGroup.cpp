#include "../../../core/scripting/generated/classes/GCAnimGraphSettingsGroup.h"
#include "../core.h"

void SetupLuaClassGCAnimGraphSettingsGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphSettingsGroup>("CAnimGraphSettingsGroup")

        .endClass();
}