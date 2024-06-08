#include "../../../core/scripting/generated/classes/GCModelConfigElement_SetBodygroup.h"
#include "../core.h"

void SetupLuaClassGCModelConfigElement_SetBodygroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_SetBodygroup>("CModelConfigElement_SetBodygroup")
        .addProperty("GroupName", &GCModelConfigElement_SetBodygroup::GetGroupName, &GCModelConfigElement_SetBodygroup::SetGroupName)
        .addProperty("Choice", &GCModelConfigElement_SetBodygroup::GetChoice, &GCModelConfigElement_SetBodygroup::SetChoice)
        .endClass();
}