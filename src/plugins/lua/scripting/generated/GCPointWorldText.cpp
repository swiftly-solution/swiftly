#include "../../../core/scripting/generated/classes/GCPointWorldText.h"
#include "../core.h"

void SetupLuaClassGCPointWorldText(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointWorldText>("CPointWorldText")
        .addProperty("MessageText", &GCPointWorldText::GetMessageText, &GCPointWorldText::SetMessageText)
        .addProperty("FontName", &GCPointWorldText::GetFontName, &GCPointWorldText::SetFontName)
        .addProperty("Enabled", &GCPointWorldText::GetEnabled, &GCPointWorldText::SetEnabled)
        .addProperty("Fullbright", &GCPointWorldText::GetFullbright, &GCPointWorldText::SetFullbright)
        .addProperty("WorldUnitsPerPx", &GCPointWorldText::GetWorldUnitsPerPx, &GCPointWorldText::SetWorldUnitsPerPx)
        .addProperty("FontSize", &GCPointWorldText::GetFontSize, &GCPointWorldText::SetFontSize)
        .addProperty("DepthOffset", &GCPointWorldText::GetDepthOffset, &GCPointWorldText::SetDepthOffset)
        .addProperty("Color", &GCPointWorldText::GetColor, &GCPointWorldText::SetColor)
        .addProperty("JustifyHorizontal", &GCPointWorldText::GetJustifyHorizontal, &GCPointWorldText::SetJustifyHorizontal)
        .addProperty("JustifyVertical", &GCPointWorldText::GetJustifyVertical, &GCPointWorldText::SetJustifyVertical)
        .addProperty("ReorientMode", &GCPointWorldText::GetReorientMode, &GCPointWorldText::SetReorientMode)
        .endClass();
}