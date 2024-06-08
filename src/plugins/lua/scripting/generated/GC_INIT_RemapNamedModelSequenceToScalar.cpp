#include "../../../core/scripting/generated/classes/GC_INIT_RemapNamedModelSequenceToScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapNamedModelSequenceToScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapNamedModelSequenceToScalar>("C_INIT_RemapNamedModelSequenceToScalar")

        .endClass();
}