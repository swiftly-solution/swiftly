#include "../../../core/scripting/generated/classes/GCLODComponentUpdater.h"
#include "../core.h"

void SetupLuaClassGCLODComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLODComponentUpdater>("CLODComponentUpdater")
        .addProperty("ServerLOD", &GCLODComponentUpdater::GetServerLOD, &GCLODComponentUpdater::SetServerLOD)
        .endClass();
}