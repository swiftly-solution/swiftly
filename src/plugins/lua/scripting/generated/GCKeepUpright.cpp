#include "../../../core/scripting/generated/classes/GCKeepUpright.h"
#include "../core.h"

void SetupLuaClassGCKeepUpright(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCKeepUpright>("CKeepUpright")
        .addProperty("WorldGoalAxis", &GCKeepUpright::GetWorldGoalAxis, &GCKeepUpright::SetWorldGoalAxis)
        .addProperty("LocalTestAxis", &GCKeepUpright::GetLocalTestAxis, &GCKeepUpright::SetLocalTestAxis)
        .addProperty("NameAttach", &GCKeepUpright::GetNameAttach, &GCKeepUpright::SetNameAttach)
        .addProperty("AttachedObject", &GCKeepUpright::GetAttachedObject, &GCKeepUpright::SetAttachedObject)
        .addProperty("AngularLimit", &GCKeepUpright::GetAngularLimit, &GCKeepUpright::SetAngularLimit)
        .addProperty("Active", &GCKeepUpright::GetActive, &GCKeepUpright::SetActive)
        .addProperty("DampAllRotation", &GCKeepUpright::GetDampAllRotation, &GCKeepUpright::SetDampAllRotation)
        .endClass();
}