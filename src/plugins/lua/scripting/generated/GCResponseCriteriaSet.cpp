#include "../../../core/scripting/generated/classes/GCResponseCriteriaSet.h"
#include "../core.h"

void SetupLuaClassGCResponseCriteriaSet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCResponseCriteriaSet>("CResponseCriteriaSet")
        .addProperty("NumPrefixedContexts", &GCResponseCriteriaSet::GetNumPrefixedContexts, &GCResponseCriteriaSet::SetNumPrefixedContexts)
        .addProperty("OverrideOnAppend", &GCResponseCriteriaSet::GetOverrideOnAppend, &GCResponseCriteriaSet::SetOverrideOnAppend)
        .endClass();
}