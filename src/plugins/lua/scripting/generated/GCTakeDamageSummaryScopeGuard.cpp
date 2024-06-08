#include "../../../core/scripting/generated/classes/GCTakeDamageSummaryScopeGuard.h"
#include "../core.h"

void SetupLuaClassGCTakeDamageSummaryScopeGuard(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTakeDamageSummaryScopeGuard>("CTakeDamageSummaryScopeGuard")
        .addProperty("Summaries", &GCTakeDamageSummaryScopeGuard::GetSummaries, &GCTakeDamageSummaryScopeGuard::SetSummaries)
        .endClass();
}