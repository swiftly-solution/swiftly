#include "../../../core/scripting/generated/classes/GC_OP_LocalAccelerationForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_LocalAccelerationForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LocalAccelerationForce>("C_OP_LocalAccelerationForce")
        .addProperty("CP", &GC_OP_LocalAccelerationForce::GetCP, &GC_OP_LocalAccelerationForce::SetCP)
        .addProperty("ScaleCP", &GC_OP_LocalAccelerationForce::GetScaleCP, &GC_OP_LocalAccelerationForce::SetScaleCP)
        .endClass();
}