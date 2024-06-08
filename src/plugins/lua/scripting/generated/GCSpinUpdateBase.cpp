#include "../../../core/scripting/generated/classes/GCSpinUpdateBase.h"
#include "../core.h"

void SetupLuaClassGCSpinUpdateBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSpinUpdateBase>("CSpinUpdateBase")

        .endClass();
}