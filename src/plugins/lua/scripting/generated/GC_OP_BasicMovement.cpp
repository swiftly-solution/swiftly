#include "../../../core/scripting/generated/classes/GC_OP_BasicMovement.h"
#include "../core.h"

void SetupLuaClassGC_OP_BasicMovement(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_BasicMovement>("C_OP_BasicMovement")
        .addProperty("Drag", &GC_OP_BasicMovement::GetDrag, &GC_OP_BasicMovement::SetDrag)
        .addProperty("MassControls", &GC_OP_BasicMovement::GetMassControls, &GC_OP_BasicMovement::SetMassControls)
        .addProperty("MaxConstraintPasses", &GC_OP_BasicMovement::GetMaxConstraintPasses, &GC_OP_BasicMovement::SetMaxConstraintPasses)
        .addProperty("UseNewCode", &GC_OP_BasicMovement::GetUseNewCode, &GC_OP_BasicMovement::SetUseNewCode)
        .endClass();
}