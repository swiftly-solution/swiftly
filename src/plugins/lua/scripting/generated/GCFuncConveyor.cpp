#include "../../../core/scripting/generated/classes/GCFuncConveyor.h"
#include "../core.h"

void SetupLuaClassGCFuncConveyor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncConveyor>("CFuncConveyor")
        .addProperty("ConveyorModels", &GCFuncConveyor::GetConveyorModels, &GCFuncConveyor::SetConveyorModels)
        .addProperty("TransitionDurationSeconds", &GCFuncConveyor::GetTransitionDurationSeconds, &GCFuncConveyor::SetTransitionDurationSeconds)
        .addProperty("MoveEntitySpace", &GCFuncConveyor::GetMoveEntitySpace, &GCFuncConveyor::SetMoveEntitySpace)
        .addProperty("MoveDirEntitySpace", &GCFuncConveyor::GetMoveDirEntitySpace, &GCFuncConveyor::SetMoveDirEntitySpace)
        .addProperty("TargetSpeed", &GCFuncConveyor::GetTargetSpeed, &GCFuncConveyor::SetTargetSpeed)
        .addProperty("TransitionDurationTicks", &GCFuncConveyor::GetTransitionDurationTicks, &GCFuncConveyor::SetTransitionDurationTicks)
        .addProperty("TransitionStartSpeed", &GCFuncConveyor::GetTransitionStartSpeed, &GCFuncConveyor::SetTransitionStartSpeed)
        .addProperty("ConveyorModels1", &GCFuncConveyor::GetConveyorModels1, &GCFuncConveyor::SetConveyorModels1)
        .endClass();
}