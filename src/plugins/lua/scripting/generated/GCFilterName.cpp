#include "../../../core/scripting/generated/classes/GCFilterName.h"
#include "../core.h"

void SetupLuaClassGCFilterName(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterName>("CFilterName")
        .addProperty("FilterName", &GCFilterName::GetFilterName, &GCFilterName::SetFilterName)
        .endClass();
}