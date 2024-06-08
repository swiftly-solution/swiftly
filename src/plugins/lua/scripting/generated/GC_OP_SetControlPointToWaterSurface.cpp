#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointToWaterSurface.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointToWaterSurface(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointToWaterSurface>("C_OP_SetControlPointToWaterSurface")
        .addProperty("SourceCP", &GC_OP_SetControlPointToWaterSurface::GetSourceCP, &GC_OP_SetControlPointToWaterSurface::SetSourceCP)
        .addProperty("DestCP", &GC_OP_SetControlPointToWaterSurface::GetDestCP, &GC_OP_SetControlPointToWaterSurface::SetDestCP)
        .addProperty("FlowCP", &GC_OP_SetControlPointToWaterSurface::GetFlowCP, &GC_OP_SetControlPointToWaterSurface::SetFlowCP)
        .addProperty("ActiveCP", &GC_OP_SetControlPointToWaterSurface::GetActiveCP, &GC_OP_SetControlPointToWaterSurface::SetActiveCP)
        .addProperty("ActiveCPField", &GC_OP_SetControlPointToWaterSurface::GetActiveCPField, &GC_OP_SetControlPointToWaterSurface::SetActiveCPField)
        .addProperty("RetestRate", &GC_OP_SetControlPointToWaterSurface::GetRetestRate, &GC_OP_SetControlPointToWaterSurface::SetRetestRate)
        .addProperty("AdaptiveThreshold", &GC_OP_SetControlPointToWaterSurface::GetAdaptiveThreshold, &GC_OP_SetControlPointToWaterSurface::SetAdaptiveThreshold)
        .endClass();
}