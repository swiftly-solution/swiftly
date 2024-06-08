#include "../../../core/scripting/generated/classes/GCAnimGraphControllerBase.h"
#include "../core.h"

void SetupLuaClassGCAnimGraphControllerBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphControllerBase>("CAnimGraphControllerBase")

        .endClass();
}