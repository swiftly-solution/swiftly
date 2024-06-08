#include "../../../core/scripting/generated/classes/GC_OP_MovementLoopInsideSphere.h"
#include "../core.h"

void SetupLuaClassGC_OP_MovementLoopInsideSphere(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_MovementLoopInsideSphere>("C_OP_MovementLoopInsideSphere")
        .addProperty("CP", &GC_OP_MovementLoopInsideSphere::GetCP, &GC_OP_MovementLoopInsideSphere::SetCP)
        .addProperty("Distance", &GC_OP_MovementLoopInsideSphere::GetDistance, &GC_OP_MovementLoopInsideSphere::SetDistance)
        .addProperty("DistSqrAttr", &GC_OP_MovementLoopInsideSphere::GetDistSqrAttr, &GC_OP_MovementLoopInsideSphere::SetDistSqrAttr)
        .endClass();
}