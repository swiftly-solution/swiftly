#include "../../../core/scripting/generated/classes/GCFootTrajectories.h"
#include "../core.h"

void SetupLuaClassGCFootTrajectories(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootTrajectories>("CFootTrajectories")
        .addProperty("Trajectories", &GCFootTrajectories::GetTrajectories, &GCFootTrajectories::SetTrajectories)
        .endClass();
}