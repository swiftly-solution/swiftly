#include "../../../core/scripting/generated/classes/GCModelConfigElement_SetMaterialGroupOnAttachedModels.h"
#include "../core.h"

void SetupLuaClassGCModelConfigElement_SetMaterialGroupOnAttachedModels(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_SetMaterialGroupOnAttachedModels>("CModelConfigElement_SetMaterialGroupOnAttachedModels")
        .addProperty("MaterialGroupName", &GCModelConfigElement_SetMaterialGroupOnAttachedModels::GetMaterialGroupName, &GCModelConfigElement_SetMaterialGroupOnAttachedModels::SetMaterialGroupName)
        .endClass();
}