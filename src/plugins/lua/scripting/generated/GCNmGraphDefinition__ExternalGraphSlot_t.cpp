#include "../../../core/scripting/generated/classes/GCNmGraphDefinition__ExternalGraphSlot_t.h"
#include "../core.h"

void SetupLuaClassGCNmGraphDefinition__ExternalGraphSlot_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmGraphDefinition__ExternalGraphSlot_t>("CNmGraphDefinition__ExternalGraphSlot_t")
        .addProperty("NodeIdx", &GCNmGraphDefinition__ExternalGraphSlot_t::GetNodeIdx, &GCNmGraphDefinition__ExternalGraphSlot_t::SetNodeIdx)
        .endClass();
}