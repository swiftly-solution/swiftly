#include "../../../core/scripting/generated/classes/GCFireSmoke.h"
#include "../core.h"

void SetupLuaClassGCFireSmoke(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFireSmoke>("CFireSmoke")
        .addProperty("FlameModelIndex", &GCFireSmoke::GetFlameModelIndex, &GCFireSmoke::SetFlameModelIndex)
        .addProperty("FlameFromAboveModelIndex", &GCFireSmoke::GetFlameFromAboveModelIndex, &GCFireSmoke::SetFlameFromAboveModelIndex)
        .endClass();
}