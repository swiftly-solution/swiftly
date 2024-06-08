#include "../../../core/scripting/generated/classes/GCParamSpanUpdater.h"
#include "../core.h"

void SetupLuaClassGCParamSpanUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParamSpanUpdater>("CParamSpanUpdater")
        .addProperty("Spans", &GCParamSpanUpdater::GetSpans, &GCParamSpanUpdater::SetSpans)
        .endClass();
}