#include "../../../core/scripting/generated/classes/GC_OP_RemapNamedModelMeshGroupOnceTimed.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapNamedModelMeshGroupOnceTimed(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapNamedModelMeshGroupOnceTimed>("C_OP_RemapNamedModelMeshGroupOnceTimed")

        .endClass();
}