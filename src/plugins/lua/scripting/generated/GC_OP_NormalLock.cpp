#include "../../../core/scripting/generated/classes/GC_OP_NormalLock.h"
#include "../core.h"

void SetupLuaClassGC_OP_NormalLock(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_NormalLock>("C_OP_NormalLock")
        .addProperty("ControlPointNumber", &GC_OP_NormalLock::GetControlPointNumber, &GC_OP_NormalLock::SetControlPointNumber)
        .endClass();
}