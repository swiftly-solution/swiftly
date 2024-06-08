#include "../../../core/scripting/generated/classes/GCEnvInstructorHint.h"
#include "../core.h"

void SetupLuaClassGCEnvInstructorHint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvInstructorHint>("CEnvInstructorHint")
        .addProperty("Name", &GCEnvInstructorHint::GetName, &GCEnvInstructorHint::SetName)
        .addProperty("Replace_Key", &GCEnvInstructorHint::GetReplace_Key, &GCEnvInstructorHint::SetReplace_Key)
        .addProperty("HintTargetEntity", &GCEnvInstructorHint::GetHintTargetEntity, &GCEnvInstructorHint::SetHintTargetEntity)
        .addProperty("Timeout", &GCEnvInstructorHint::GetTimeout, &GCEnvInstructorHint::SetTimeout)
        .addProperty("DisplayLimit", &GCEnvInstructorHint::GetDisplayLimit, &GCEnvInstructorHint::SetDisplayLimit)
        .addProperty("Icon_Onscreen", &GCEnvInstructorHint::GetIcon_Onscreen, &GCEnvInstructorHint::SetIcon_Onscreen)
        .addProperty("Icon_Offscreen", &GCEnvInstructorHint::GetIcon_Offscreen, &GCEnvInstructorHint::SetIcon_Offscreen)
        .addProperty("Caption", &GCEnvInstructorHint::GetCaption, &GCEnvInstructorHint::SetCaption)
        .addProperty("ActivatorCaption", &GCEnvInstructorHint::GetActivatorCaption, &GCEnvInstructorHint::SetActivatorCaption)
        .addProperty("Color", &GCEnvInstructorHint::GetColor, &GCEnvInstructorHint::SetColor)
        .addProperty("IconOffset", &GCEnvInstructorHint::GetIconOffset, &GCEnvInstructorHint::SetIconOffset)
        .addProperty("Range", &GCEnvInstructorHint::GetRange, &GCEnvInstructorHint::SetRange)
        .addProperty("PulseOption", &GCEnvInstructorHint::GetPulseOption, &GCEnvInstructorHint::SetPulseOption)
        .addProperty("AlphaOption", &GCEnvInstructorHint::GetAlphaOption, &GCEnvInstructorHint::SetAlphaOption)
        .addProperty("ShakeOption", &GCEnvInstructorHint::GetShakeOption, &GCEnvInstructorHint::SetShakeOption)
        .addProperty("Static", &GCEnvInstructorHint::GetStatic, &GCEnvInstructorHint::SetStatic)
        .addProperty("NoOffscreen", &GCEnvInstructorHint::GetNoOffscreen, &GCEnvInstructorHint::SetNoOffscreen)
        .addProperty("ForceCaption", &GCEnvInstructorHint::GetForceCaption, &GCEnvInstructorHint::SetForceCaption)
        .addProperty("InstanceType", &GCEnvInstructorHint::GetInstanceType, &GCEnvInstructorHint::SetInstanceType)
        .addProperty("SuppressRest", &GCEnvInstructorHint::GetSuppressRest, &GCEnvInstructorHint::SetSuppressRest)
        .addProperty("Binding", &GCEnvInstructorHint::GetBinding, &GCEnvInstructorHint::SetBinding)
        .addProperty("AllowNoDrawTarget", &GCEnvInstructorHint::GetAllowNoDrawTarget, &GCEnvInstructorHint::SetAllowNoDrawTarget)
        .addProperty("AutoStart", &GCEnvInstructorHint::GetAutoStart, &GCEnvInstructorHint::SetAutoStart)
        .addProperty("LocalPlayerOnly", &GCEnvInstructorHint::GetLocalPlayerOnly, &GCEnvInstructorHint::SetLocalPlayerOnly)
        .endClass();
}