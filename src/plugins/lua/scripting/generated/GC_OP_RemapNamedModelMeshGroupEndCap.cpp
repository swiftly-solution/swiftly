#include "../../../core/scripting/generated/classes/GC_OP_RemapNamedModelMeshGroupEndCap.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapNamedModelMeshGroupEndCap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapNamedModelMeshGroupEndCap>("C_OP_RemapNamedModelMeshGroupEndCap")

        .endClass();
}