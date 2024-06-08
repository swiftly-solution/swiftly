#include "../../../core/scripting/generated/classes/GC_INIT_RemapNamedModelMeshGroupToScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapNamedModelMeshGroupToScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapNamedModelMeshGroupToScalar>("C_INIT_RemapNamedModelMeshGroupToScalar")

        .endClass();
}