#include "../../../core/scripting/generated/classes/GCItemGenericTriggerHelper.h"
#include "../core.h"

void SetupLuaClassGCItemGenericTriggerHelper(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemGenericTriggerHelper>("CItemGenericTriggerHelper")

        .endClass();
}