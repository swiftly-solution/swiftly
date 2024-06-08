#include "../../../core/scripting/generated/classes/GC_OP_RemapNamedModelSequenceEndCap.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapNamedModelSequenceEndCap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapNamedModelSequenceEndCap>("C_OP_RemapNamedModelSequenceEndCap")

        .endClass();
}