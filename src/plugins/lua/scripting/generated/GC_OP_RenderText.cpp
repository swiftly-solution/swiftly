#include "../../../core/scripting/generated/classes/GC_OP_RenderText.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderText(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderText>("C_OP_RenderText")
        .addProperty("OutlineColor", &GC_OP_RenderText::GetOutlineColor, &GC_OP_RenderText::SetOutlineColor)
        .addProperty("DefaultText", &GC_OP_RenderText::GetDefaultText, &GC_OP_RenderText::SetDefaultText)
        .endClass();
}