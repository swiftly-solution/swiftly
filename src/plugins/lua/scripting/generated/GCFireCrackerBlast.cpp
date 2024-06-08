#include "../../../core/scripting/generated/classes/GCFireCrackerBlast.h"
#include "../core.h"

void SetupLuaClassGCFireCrackerBlast(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFireCrackerBlast>("CFireCrackerBlast")

        .endClass();
}