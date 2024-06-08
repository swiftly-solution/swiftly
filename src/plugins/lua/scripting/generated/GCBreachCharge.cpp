#include "../../../core/scripting/generated/classes/GCBreachCharge.h"
#include "../core.h"

void SetupLuaClassGCBreachCharge(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBreachCharge>("CBreachCharge")

        .endClass();
}