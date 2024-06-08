#include "../../../core/scripting/generated/classes/GCModelConfigList.h"
#include "../core.h"

void SetupLuaClassGCModelConfigList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigList>("CModelConfigList")
        .addProperty("HideMaterialGroupInTools", &GCModelConfigList::GetHideMaterialGroupInTools, &GCModelConfigList::SetHideMaterialGroupInTools)
        .addProperty("HideRenderColorInTools", &GCModelConfigList::GetHideRenderColorInTools, &GCModelConfigList::SetHideRenderColorInTools)
        .addProperty("Configs", &GCModelConfigList::GetConfigs, &GCModelConfigList::SetConfigs)
        .endClass();
}