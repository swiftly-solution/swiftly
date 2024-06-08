#include "../../../core/scripting/generated/classes/GC_OP_RemapNamedModelBodyPartEndCap.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapNamedModelBodyPartEndCap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapNamedModelBodyPartEndCap>("C_OP_RemapNamedModelBodyPartEndCap")

        .endClass();
}