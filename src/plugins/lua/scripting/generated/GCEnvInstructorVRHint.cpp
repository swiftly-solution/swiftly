#include "../../../core/scripting/generated/classes/GCEnvInstructorVRHint.h"
#include "../core.h"

void SetupLuaClassGCEnvInstructorVRHint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvInstructorVRHint>("CEnvInstructorVRHint")
        .addProperty("Name", &GCEnvInstructorVRHint::GetName, &GCEnvInstructorVRHint::SetName)
        .addProperty("HintTargetEntity", &GCEnvInstructorVRHint::GetHintTargetEntity, &GCEnvInstructorVRHint::SetHintTargetEntity)
        .addProperty("Timeout", &GCEnvInstructorVRHint::GetTimeout, &GCEnvInstructorVRHint::SetTimeout)
        .addProperty("Caption", &GCEnvInstructorVRHint::GetCaption, &GCEnvInstructorVRHint::SetCaption)
        .addProperty("StartSound", &GCEnvInstructorVRHint::GetStartSound, &GCEnvInstructorVRHint::SetStartSound)
        .addProperty("LayoutFileType", &GCEnvInstructorVRHint::GetLayoutFileType, &GCEnvInstructorVRHint::SetLayoutFileType)
        .addProperty("CustomLayoutFile", &GCEnvInstructorVRHint::GetCustomLayoutFile, &GCEnvInstructorVRHint::SetCustomLayoutFile)
        .addProperty("AttachType", &GCEnvInstructorVRHint::GetAttachType, &GCEnvInstructorVRHint::SetAttachType)
        .addProperty("HeightOffset", &GCEnvInstructorVRHint::GetHeightOffset, &GCEnvInstructorVRHint::SetHeightOffset)
        .endClass();
}