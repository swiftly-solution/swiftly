#include "../../../core/scripting/generated/classes/GCFuncInteractionLayerClip.h"
#include "../core.h"

void SetupLuaClassGCFuncInteractionLayerClip(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncInteractionLayerClip>("CFuncInteractionLayerClip")
        .addProperty("Disabled", &GCFuncInteractionLayerClip::GetDisabled, &GCFuncInteractionLayerClip::SetDisabled)
        .addProperty("InteractsAs", &GCFuncInteractionLayerClip::GetInteractsAs, &GCFuncInteractionLayerClip::SetInteractsAs)
        .addProperty("InteractsWith", &GCFuncInteractionLayerClip::GetInteractsWith, &GCFuncInteractionLayerClip::SetInteractsWith)
        .endClass();
}