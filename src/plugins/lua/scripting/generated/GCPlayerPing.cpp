#include "../../../core/scripting/generated/classes/GCPlayerPing.h"
#include "../core.h"

void SetupLuaClassGCPlayerPing(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerPing>("CPlayerPing")
        .addProperty("Player", &GCPlayerPing::GetPlayer, &GCPlayerPing::SetPlayer)
        .addProperty("PingedEntity", &GCPlayerPing::GetPingedEntity, &GCPlayerPing::SetPingedEntity)
        .addProperty("Type", &GCPlayerPing::GetType, &GCPlayerPing::SetType)
        .addProperty("Urgent", &GCPlayerPing::GetUrgent, &GCPlayerPing::SetUrgent)
        .addProperty("PlaceName", &GCPlayerPing::GetPlaceName, &GCPlayerPing::SetPlaceName)
        .endClass();
}