#include "../../../core/scripting/generated/classes/GCFuncTrackChange.h"
#include "../core.h"

void SetupLuaClassGCFuncTrackChange(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTrackChange>("CFuncTrackChange")
        .addProperty("TrackTop", &GCFuncTrackChange::GetTrackTop, &GCFuncTrackChange::SetTrackTop)
        .addProperty("TrackBottom", &GCFuncTrackChange::GetTrackBottom, &GCFuncTrackChange::SetTrackBottom)
        .addProperty("Train", &GCFuncTrackChange::GetTrain, &GCFuncTrackChange::SetTrain)
        .addProperty("TrackTopName", &GCFuncTrackChange::GetTrackTopName, &GCFuncTrackChange::SetTrackTopName)
        .addProperty("TrackBottomName", &GCFuncTrackChange::GetTrackBottomName, &GCFuncTrackChange::SetTrackBottomName)
        .addProperty("TrainName", &GCFuncTrackChange::GetTrainName, &GCFuncTrackChange::SetTrainName)
        .addProperty("Code", &GCFuncTrackChange::GetCode, &GCFuncTrackChange::SetCode)
        .addProperty("TargetState", &GCFuncTrackChange::GetTargetState, &GCFuncTrackChange::SetTargetState)
        .addProperty("Use", &GCFuncTrackChange::GetUse, &GCFuncTrackChange::SetUse)
        .endClass();
}