#include "../../../core/scripting/generated/classes/GCHostageCarriableProp.h"
#include "../core.h"

void SetupLuaClassGCHostageCarriableProp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHostageCarriableProp>("CHostageCarriableProp")

        .endClass();
}