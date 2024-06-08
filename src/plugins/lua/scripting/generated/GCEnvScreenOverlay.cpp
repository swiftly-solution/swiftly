#include "../../../core/scripting/generated/classes/GCEnvScreenOverlay.h"
#include "../core.h"

void SetupLuaClassGCEnvScreenOverlay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvScreenOverlay>("CEnvScreenOverlay")
        .addProperty("OverlayNames", &GCEnvScreenOverlay::GetOverlayNames, &GCEnvScreenOverlay::SetOverlayNames)
        .addProperty("OverlayTimes", &GCEnvScreenOverlay::GetOverlayTimes, &GCEnvScreenOverlay::SetOverlayTimes)
        .addProperty("DesiredOverlay", &GCEnvScreenOverlay::GetDesiredOverlay, &GCEnvScreenOverlay::SetDesiredOverlay)
        .addProperty("IsActive", &GCEnvScreenOverlay::GetIsActive, &GCEnvScreenOverlay::SetIsActive)
        .endClass();
}