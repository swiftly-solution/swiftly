#include "../../../core/scripting/generated/classes/GCTriggerToggleSave.h"
#include "../core.h"

void SetupLuaClassGCTriggerToggleSave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerToggleSave>("CTriggerToggleSave")

        .endClass();
}