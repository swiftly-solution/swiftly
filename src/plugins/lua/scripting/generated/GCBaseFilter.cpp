#include "../../../core/scripting/generated/classes/GCBaseFilter.h"
#include "../core.h"

void SetupLuaClassGCBaseFilter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseFilter>("CBaseFilter")
        .addProperty("Negated", &GCBaseFilter::GetNegated, &GCBaseFilter::SetNegated)
        .addProperty("OnPass", &GCBaseFilter::GetOnPass, &GCBaseFilter::SetOnPass)
        .addProperty("OnFail", &GCBaseFilter::GetOnFail, &GCBaseFilter::SetOnFail)
        .endClass();
}