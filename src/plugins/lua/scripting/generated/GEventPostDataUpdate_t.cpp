#include "../../../core/scripting/generated/classes/GEventPostDataUpdate_t.h"
#include "../core.h"

void SetupLuaClassGEventPostDataUpdate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventPostDataUpdate_t>("EventPostDataUpdate_t")
        .addProperty("Count", &GEventPostDataUpdate_t::GetCount, &GEventPostDataUpdate_t::SetCount)
        .endClass();
}