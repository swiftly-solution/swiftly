#include "../../../core/scripting/generated/classes/GInfoOverlayData_t.h"
#include "../core.h"

void SetupLuaClassGInfoOverlayData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GInfoOverlayData_t>("InfoOverlayData_t")
        .addProperty("Transform", &GInfoOverlayData_t::GetTransform, &GInfoOverlayData_t::SetTransform)
        .addProperty("Width", &GInfoOverlayData_t::GetWidth, &GInfoOverlayData_t::SetWidth)
        .addProperty("Height", &GInfoOverlayData_t::GetHeight, &GInfoOverlayData_t::SetHeight)
        .addProperty("Depth", &GInfoOverlayData_t::GetDepth, &GInfoOverlayData_t::SetDepth)
        .addProperty("UVStart", &GInfoOverlayData_t::GetUVStart, &GInfoOverlayData_t::SetUVStart)
        .addProperty("UVEnd", &GInfoOverlayData_t::GetUVEnd, &GInfoOverlayData_t::SetUVEnd)
        .addProperty("RenderOrder", &GInfoOverlayData_t::GetRenderOrder, &GInfoOverlayData_t::SetRenderOrder)
        .addProperty("TintColor", &GInfoOverlayData_t::GetTintColor, &GInfoOverlayData_t::SetTintColor)
        .addProperty("SequenceOverride", &GInfoOverlayData_t::GetSequenceOverride, &GInfoOverlayData_t::SetSequenceOverride)
        .endClass();
}