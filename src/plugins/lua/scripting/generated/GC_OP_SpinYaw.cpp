#include "../../../core/scripting/generated/classes/GC_OP_SpinYaw.h"
#include "../core.h"

void SetupLuaClassGC_OP_SpinYaw(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SpinYaw>("C_OP_SpinYaw")

        .endClass();
}