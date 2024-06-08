#include "../../../core/scripting/generated/classes/GC_OP_RemapNamedModelSequenceOnceTimed.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapNamedModelSequenceOnceTimed(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapNamedModelSequenceOnceTimed>("C_OP_RemapNamedModelSequenceOnceTimed")

        .endClass();
}