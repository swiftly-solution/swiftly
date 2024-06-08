#include "../../../core/scripting/generated/classes/GC_INIT_PositionWarpScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_PositionWarpScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_PositionWarpScalar>("C_INIT_PositionWarpScalar")
        .addProperty("WarpMin", &GC_INIT_PositionWarpScalar::GetWarpMin, &GC_INIT_PositionWarpScalar::SetWarpMin)
        .addProperty("WarpMax", &GC_INIT_PositionWarpScalar::GetWarpMax, &GC_INIT_PositionWarpScalar::SetWarpMax)
        .addProperty("InputValue", &GC_INIT_PositionWarpScalar::GetInputValue, &GC_INIT_PositionWarpScalar::SetInputValue)
        .addProperty("PrevPosScale", &GC_INIT_PositionWarpScalar::GetPrevPosScale, &GC_INIT_PositionWarpScalar::SetPrevPosScale)
        .addProperty("ScaleControlPointNumber", &GC_INIT_PositionWarpScalar::GetScaleControlPointNumber, &GC_INIT_PositionWarpScalar::SetScaleControlPointNumber)
        .addProperty("ControlPointNumber", &GC_INIT_PositionWarpScalar::GetControlPointNumber, &GC_INIT_PositionWarpScalar::SetControlPointNumber)
        .endClass();
}