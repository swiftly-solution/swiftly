#include "../../../core/scripting/generated/classes/GCModelConfigElement_SetRenderColor.h"
#include "../core.h"

void SetupLuaClassGCModelConfigElement_SetRenderColor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_SetRenderColor>("CModelConfigElement_SetRenderColor")
        .addProperty("Color", &GCModelConfigElement_SetRenderColor::GetColor, &GCModelConfigElement_SetRenderColor::SetColor)
        .endClass();
}