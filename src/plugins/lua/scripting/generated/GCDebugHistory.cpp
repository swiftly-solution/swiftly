#include "../../../core/scripting/generated/classes/GCDebugHistory.h"
#include "../core.h"

void SetupLuaClassGCDebugHistory(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDebugHistory>("CDebugHistory")
        .addProperty("NpcEvents", &GCDebugHistory::GetNpcEvents, &GCDebugHistory::SetNpcEvents)
        .endClass();
}