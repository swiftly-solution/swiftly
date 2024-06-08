#include "../../../core/scripting/generated/classes/GC_OP_RemapNamedModelBodyPartOnceTimed.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapNamedModelBodyPartOnceTimed(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapNamedModelBodyPartOnceTimed>("C_OP_RemapNamedModelBodyPartOnceTimed")

        .endClass();
}