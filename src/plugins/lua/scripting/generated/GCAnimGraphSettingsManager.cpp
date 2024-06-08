#include "../../../core/scripting/generated/classes/GCAnimGraphSettingsManager.h"
#include "../core.h"

void SetupLuaClassGCAnimGraphSettingsManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphSettingsManager>("CAnimGraphSettingsManager")

        .endClass();
}