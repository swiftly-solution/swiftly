#include "../../../core/scripting/generated/classes/GCPointTeleport.h"
#include "../core.h"

void SetupLuaClassGCPointTeleport(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointTeleport>("CPointTeleport")
        .addProperty("SaveOrigin", &GCPointTeleport::GetSaveOrigin, &GCPointTeleport::SetSaveOrigin)
        .addProperty("SaveAngles", &GCPointTeleport::GetSaveAngles, &GCPointTeleport::SetSaveAngles)
        .addProperty("TeleportParentedEntities", &GCPointTeleport::GetTeleportParentedEntities, &GCPointTeleport::SetTeleportParentedEntities)
        .addProperty("TeleportUseCurrentAngle", &GCPointTeleport::GetTeleportUseCurrentAngle, &GCPointTeleport::SetTeleportUseCurrentAngle)
        .endClass();
}