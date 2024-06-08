#include "../../../core/scripting/generated/classes/GCTriggerTeleport.h"
#include "../core.h"

void SetupLuaClassGCTriggerTeleport(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerTeleport>("CTriggerTeleport")
        .addProperty("Landmark", &GCTriggerTeleport::GetLandmark, &GCTriggerTeleport::SetLandmark)
        .addProperty("UseLandmarkAngles", &GCTriggerTeleport::GetUseLandmarkAngles, &GCTriggerTeleport::SetUseLandmarkAngles)
        .addProperty("MirrorPlayer", &GCTriggerTeleport::GetMirrorPlayer, &GCTriggerTeleport::SetMirrorPlayer)
        .endClass();
}