#include "../../../core/scripting/generated/classes/GCPointGiveAmmo.h"
#include "../core.h"

void SetupLuaClassGCPointGiveAmmo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointGiveAmmo>("CPointGiveAmmo")
        .addProperty("Activator", &GCPointGiveAmmo::GetActivator, &GCPointGiveAmmo::SetActivator)
        .endClass();
}