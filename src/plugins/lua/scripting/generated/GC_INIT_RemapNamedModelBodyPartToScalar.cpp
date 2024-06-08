#include "../../../core/scripting/generated/classes/GC_INIT_RemapNamedModelBodyPartToScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapNamedModelBodyPartToScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapNamedModelBodyPartToScalar>("C_INIT_RemapNamedModelBodyPartToScalar")

        .endClass();
}