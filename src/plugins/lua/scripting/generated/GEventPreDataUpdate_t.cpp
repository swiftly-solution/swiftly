#include "../../../core/scripting/generated/classes/GEventPreDataUpdate_t.h"
#include "../core.h"

void SetupLuaClassGEventPreDataUpdate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventPreDataUpdate_t>("EventPreDataUpdate_t")
        .addProperty("Count", &GEventPreDataUpdate_t::GetCount, &GEventPreDataUpdate_t::SetCount)
        .endClass();
}