#include "../../../core/scripting/generated/classes/GStanceInfo_t.h"
#include "../core.h"

void SetupLuaClassGStanceInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GStanceInfo_t>("StanceInfo_t")
        .addProperty("Position", &GStanceInfo_t::GetPosition, &GStanceInfo_t::SetPosition)
        .addProperty("Direction", &GStanceInfo_t::GetDirection, &GStanceInfo_t::SetDirection)
        .endClass();
}