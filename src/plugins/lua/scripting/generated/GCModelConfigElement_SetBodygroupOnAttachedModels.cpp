#include "../../../core/scripting/generated/classes/GCModelConfigElement_SetBodygroupOnAttachedModels.h"
#include "../core.h"

void SetupLuaClassGCModelConfigElement_SetBodygroupOnAttachedModels(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_SetBodygroupOnAttachedModels>("CModelConfigElement_SetBodygroupOnAttachedModels")
        .addProperty("GroupName", &GCModelConfigElement_SetBodygroupOnAttachedModels::GetGroupName, &GCModelConfigElement_SetBodygroupOnAttachedModels::SetGroupName)
        .addProperty("Choice", &GCModelConfigElement_SetBodygroupOnAttachedModels::GetChoice, &GCModelConfigElement_SetBodygroupOnAttachedModels::SetChoice)
        .endClass();
}