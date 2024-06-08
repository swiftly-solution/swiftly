#include "../../../core/scripting/generated/classes/GCModelConfig.h"
#include "../core.h"

void SetupLuaClassGCModelConfig(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfig>("CModelConfig")
        .addProperty("ConfigName", &GCModelConfig::GetConfigName, &GCModelConfig::SetConfigName)
        .addProperty("Elements", &GCModelConfig::GetElements, &GCModelConfig::SetElements)
        .addProperty("TopLevel", &GCModelConfig::GetTopLevel, &GCModelConfig::SetTopLevel)
        .endClass();
}