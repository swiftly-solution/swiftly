#include "../../../core/scripting/generated/classes/GCFilterContext.h"
#include "../core.h"

void SetupLuaClassGCFilterContext(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterContext>("CFilterContext")
        .addProperty("FilterContext", &GCFilterContext::GetFilterContext, &GCFilterContext::SetFilterContext)
        .endClass();
}