#include "../../../core/scripting/generated/classes/GCFuncNavBlocker.h"
#include "../core.h"

void SetupLuaClassGCFuncNavBlocker(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncNavBlocker>("CFuncNavBlocker")
        .addProperty("Disabled", &GCFuncNavBlocker::GetDisabled, &GCFuncNavBlocker::SetDisabled)
        .addProperty("BlockedTeamNumber", &GCFuncNavBlocker::GetBlockedTeamNumber, &GCFuncNavBlocker::SetBlockedTeamNumber)
        .endClass();
}