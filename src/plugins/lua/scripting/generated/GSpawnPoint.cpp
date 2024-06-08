#include "../../../core/scripting/generated/classes/GSpawnPoint.h"
#include "../core.h"

void SetupLuaClassGSpawnPoint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSpawnPoint>("SpawnPoint")
        .addProperty("Priority", &GSpawnPoint::GetPriority, &GSpawnPoint::SetPriority)
        .addProperty("Enabled", &GSpawnPoint::GetEnabled, &GSpawnPoint::SetEnabled)
        .addProperty("Type", &GSpawnPoint::GetType, &GSpawnPoint::SetType)
        .endClass();
}