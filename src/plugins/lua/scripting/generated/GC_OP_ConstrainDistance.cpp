#include "../../../core/scripting/generated/classes/GC_OP_ConstrainDistance.h"
#include "../core.h"

void SetupLuaClassGC_OP_ConstrainDistance(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ConstrainDistance>("C_OP_ConstrainDistance")
        .addProperty("MinDistance", &GC_OP_ConstrainDistance::GetMinDistance, &GC_OP_ConstrainDistance::SetMinDistance)
        .addProperty("MaxDistance", &GC_OP_ConstrainDistance::GetMaxDistance, &GC_OP_ConstrainDistance::SetMaxDistance)
        .addProperty("ControlPointNumber", &GC_OP_ConstrainDistance::GetControlPointNumber, &GC_OP_ConstrainDistance::SetControlPointNumber)
        .addProperty("CenterOffset", &GC_OP_ConstrainDistance::GetCenterOffset, &GC_OP_ConstrainDistance::SetCenterOffset)
        .addProperty("GlobalCenter", &GC_OP_ConstrainDistance::GetGlobalCenter, &GC_OP_ConstrainDistance::SetGlobalCenter)
        .endClass();
}