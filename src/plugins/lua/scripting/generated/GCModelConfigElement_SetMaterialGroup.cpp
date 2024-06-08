#include "../../../core/scripting/generated/classes/GCModelConfigElement_SetMaterialGroup.h"
#include "../core.h"

void SetupLuaClassGCModelConfigElement_SetMaterialGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_SetMaterialGroup>("CModelConfigElement_SetMaterialGroup")
        .addProperty("MaterialGroupName", &GCModelConfigElement_SetMaterialGroup::GetMaterialGroupName, &GCModelConfigElement_SetMaterialGroup::SetMaterialGroupName)
        .endClass();
}