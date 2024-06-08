#include "../../../core/scripting/generated/classes/GFilterTeam.h"
#include "../core.h"

void SetupLuaClassGFilterTeam(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFilterTeam>("FilterTeam")
        .addProperty("FilterTeam", &GFilterTeam::GetFilterTeam, &GFilterTeam::SetFilterTeam)
        .endClass();
}