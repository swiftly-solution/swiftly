#include "../../../core/scripting/generated/classes/GC_INIT_RandomNamedModelMeshGroup.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomNamedModelMeshGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomNamedModelMeshGroup>("C_INIT_RandomNamedModelMeshGroup")

        .endClass();
}