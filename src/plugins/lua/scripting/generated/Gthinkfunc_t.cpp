#include "../../../core/scripting/generated/classes/Gthinkfunc_t.h"
#include "../core.h"

void SetupLuaClassGthinkfunc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gthinkfunc_t>("thinkfunc_t")
        .addProperty("Context", &Gthinkfunc_t::GetContext, &Gthinkfunc_t::SetContext)
        .endClass();
}