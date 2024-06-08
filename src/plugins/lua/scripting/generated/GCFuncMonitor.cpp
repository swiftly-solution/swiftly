#include "../../../core/scripting/generated/classes/GCFuncMonitor.h"
#include "../core.h"

void SetupLuaClassGCFuncMonitor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncMonitor>("CFuncMonitor")
        .addProperty("TargetCamera", &GCFuncMonitor::GetTargetCamera, &GCFuncMonitor::SetTargetCamera)
        .addProperty("ResolutionEnum", &GCFuncMonitor::GetResolutionEnum, &GCFuncMonitor::SetResolutionEnum)
        .addProperty("RenderShadows", &GCFuncMonitor::GetRenderShadows, &GCFuncMonitor::SetRenderShadows)
        .addProperty("UseUniqueColorTarget", &GCFuncMonitor::GetUseUniqueColorTarget, &GCFuncMonitor::SetUseUniqueColorTarget)
        .addProperty("BrushModelName", &GCFuncMonitor::GetBrushModelName, &GCFuncMonitor::SetBrushModelName)
        .addProperty("TargetCamera1", &GCFuncMonitor::GetTargetCamera1, &GCFuncMonitor::SetTargetCamera1)
        .addProperty("Enabled", &GCFuncMonitor::GetEnabled, &GCFuncMonitor::SetEnabled)
        .addProperty("Draw3DSkybox", &GCFuncMonitor::GetDraw3DSkybox, &GCFuncMonitor::SetDraw3DSkybox)
        .addProperty("StartEnabled", &GCFuncMonitor::GetStartEnabled, &GCFuncMonitor::SetStartEnabled)
        .endClass();
}