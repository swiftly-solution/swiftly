#include "../../../core/scripting/generated/classes/GCPointClientUIWorldPanel.h"
#include "../core.h"

void SetupLuaClassGCPointClientUIWorldPanel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointClientUIWorldPanel>("CPointClientUIWorldPanel")
        .addProperty("IgnoreInput", &GCPointClientUIWorldPanel::GetIgnoreInput, &GCPointClientUIWorldPanel::SetIgnoreInput)
        .addProperty("Lit", &GCPointClientUIWorldPanel::GetLit, &GCPointClientUIWorldPanel::SetLit)
        .addProperty("FollowPlayerAcrossTeleport", &GCPointClientUIWorldPanel::GetFollowPlayerAcrossTeleport, &GCPointClientUIWorldPanel::SetFollowPlayerAcrossTeleport)
        .addProperty("Width", &GCPointClientUIWorldPanel::GetWidth, &GCPointClientUIWorldPanel::SetWidth)
        .addProperty("Height", &GCPointClientUIWorldPanel::GetHeight, &GCPointClientUIWorldPanel::SetHeight)
        .addProperty("DPI", &GCPointClientUIWorldPanel::GetDPI, &GCPointClientUIWorldPanel::SetDPI)
        .addProperty("InteractDistance", &GCPointClientUIWorldPanel::GetInteractDistance, &GCPointClientUIWorldPanel::SetInteractDistance)
        .addProperty("DepthOffset", &GCPointClientUIWorldPanel::GetDepthOffset, &GCPointClientUIWorldPanel::SetDepthOffset)
        .addProperty("OwnerContext", &GCPointClientUIWorldPanel::GetOwnerContext, &GCPointClientUIWorldPanel::SetOwnerContext)
        .addProperty("HorizontalAlign", &GCPointClientUIWorldPanel::GetHorizontalAlign, &GCPointClientUIWorldPanel::SetHorizontalAlign)
        .addProperty("VerticalAlign", &GCPointClientUIWorldPanel::GetVerticalAlign, &GCPointClientUIWorldPanel::SetVerticalAlign)
        .addProperty("Orientation", &GCPointClientUIWorldPanel::GetOrientation, &GCPointClientUIWorldPanel::SetOrientation)
        .addProperty("AllowInteractionFromAllSceneWorlds", &GCPointClientUIWorldPanel::GetAllowInteractionFromAllSceneWorlds, &GCPointClientUIWorldPanel::SetAllowInteractionFromAllSceneWorlds)
        .addProperty("CSSClasses", &GCPointClientUIWorldPanel::GetCSSClasses, &GCPointClientUIWorldPanel::SetCSSClasses)
        .addProperty("Opaque", &GCPointClientUIWorldPanel::GetOpaque, &GCPointClientUIWorldPanel::SetOpaque)
        .addProperty("NoDepth", &GCPointClientUIWorldPanel::GetNoDepth, &GCPointClientUIWorldPanel::SetNoDepth)
        .addProperty("RenderBackface", &GCPointClientUIWorldPanel::GetRenderBackface, &GCPointClientUIWorldPanel::SetRenderBackface)
        .addProperty("UseOffScreenIndicator", &GCPointClientUIWorldPanel::GetUseOffScreenIndicator, &GCPointClientUIWorldPanel::SetUseOffScreenIndicator)
        .addProperty("ExcludeFromSaveGames", &GCPointClientUIWorldPanel::GetExcludeFromSaveGames, &GCPointClientUIWorldPanel::SetExcludeFromSaveGames)
        .addProperty("Grabbable", &GCPointClientUIWorldPanel::GetGrabbable, &GCPointClientUIWorldPanel::SetGrabbable)
        .addProperty("OnlyRenderToTexture", &GCPointClientUIWorldPanel::GetOnlyRenderToTexture, &GCPointClientUIWorldPanel::SetOnlyRenderToTexture)
        .addProperty("DisableMipGen", &GCPointClientUIWorldPanel::GetDisableMipGen, &GCPointClientUIWorldPanel::SetDisableMipGen)
        .addProperty("ExplicitImageLayout", &GCPointClientUIWorldPanel::GetExplicitImageLayout, &GCPointClientUIWorldPanel::SetExplicitImageLayout)
        .endClass();
}