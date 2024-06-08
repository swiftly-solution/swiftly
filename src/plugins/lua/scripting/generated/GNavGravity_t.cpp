#include "../../../core/scripting/generated/classes/GNavGravity_t.h"
#include "../core.h"

void SetupLuaClassGNavGravity_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNavGravity_t>("NavGravity_t")
        .addProperty("Gravity", &GNavGravity_t::GetGravity, &GNavGravity_t::SetGravity)
        .addProperty("Default", &GNavGravity_t::GetDefault, &GNavGravity_t::SetDefault)
        .endClass();
}