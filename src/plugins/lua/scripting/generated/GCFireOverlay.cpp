#include "../../../core/scripting/generated/classes/GCFireOverlay.h"
#include "../core.h"

void SetupLuaClassGCFireOverlay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFireOverlay>("CFireOverlay")
        .addProperty("BaseColors", &GCFireOverlay::GetBaseColors, &GCFireOverlay::SetBaseColors)
        .addProperty("Scale", &GCFireOverlay::GetScale, &GCFireOverlay::SetScale)
        .addProperty("GUID", &GCFireOverlay::GetGUID, &GCFireOverlay::SetGUID)
        .endClass();
}