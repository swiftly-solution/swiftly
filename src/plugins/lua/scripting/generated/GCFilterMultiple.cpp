#include "../../../core/scripting/generated/classes/GCFilterMultiple.h"
#include "../core.h"

void SetupLuaClassGCFilterMultiple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterMultiple>("CFilterMultiple")
        .addProperty("FilterType", &GCFilterMultiple::GetFilterType, &GCFilterMultiple::SetFilterType)
        .addProperty("FilterName", &GCFilterMultiple::GetFilterName, &GCFilterMultiple::SetFilterName)
        .addProperty("Filter", &GCFilterMultiple::GetFilter, &GCFilterMultiple::SetFilter)
        .addProperty("FilterCount", &GCFilterMultiple::GetFilterCount, &GCFilterMultiple::SetFilterCount)
        .endClass();
}