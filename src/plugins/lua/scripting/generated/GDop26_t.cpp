#include "../../../core/scripting/generated/classes/GDop26_t.h"
#include "../core.h"

void SetupLuaClassGDop26_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GDop26_t>("Dop26_t")
        .addProperty("Support", &GDop26_t::GetSupport, &GDop26_t::SetSupport)
        .endClass();
}