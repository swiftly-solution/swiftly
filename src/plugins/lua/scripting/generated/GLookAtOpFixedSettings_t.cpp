#include "../../../core/scripting/generated/classes/GLookAtOpFixedSettings_t.h"
#include "../core.h"

void SetupLuaClassGLookAtOpFixedSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GLookAtOpFixedSettings_t>("LookAtOpFixedSettings_t")
        .addProperty("Attachment", &GLookAtOpFixedSettings_t::GetAttachment, &GLookAtOpFixedSettings_t::SetAttachment)
        .addProperty("Damping", &GLookAtOpFixedSettings_t::GetDamping, &GLookAtOpFixedSettings_t::SetDamping)
        .addProperty("Bones", &GLookAtOpFixedSettings_t::GetBones, &GLookAtOpFixedSettings_t::SetBones)
        .addProperty("YawLimit", &GLookAtOpFixedSettings_t::GetYawLimit, &GLookAtOpFixedSettings_t::SetYawLimit)
        .addProperty("PitchLimit", &GLookAtOpFixedSettings_t::GetPitchLimit, &GLookAtOpFixedSettings_t::SetPitchLimit)
        .addProperty("HysteresisInnerAngle", &GLookAtOpFixedSettings_t::GetHysteresisInnerAngle, &GLookAtOpFixedSettings_t::SetHysteresisInnerAngle)
        .addProperty("HysteresisOuterAngle", &GLookAtOpFixedSettings_t::GetHysteresisOuterAngle, &GLookAtOpFixedSettings_t::SetHysteresisOuterAngle)
        .addProperty("RotateYawForward", &GLookAtOpFixedSettings_t::GetRotateYawForward, &GLookAtOpFixedSettings_t::SetRotateYawForward)
        .addProperty("MaintainUpDirection", &GLookAtOpFixedSettings_t::GetMaintainUpDirection, &GLookAtOpFixedSettings_t::SetMaintainUpDirection)
        .addProperty("TargetIsPosition", &GLookAtOpFixedSettings_t::GetTargetIsPosition, &GLookAtOpFixedSettings_t::SetTargetIsPosition)
        .addProperty("UseHysteresis", &GLookAtOpFixedSettings_t::GetUseHysteresis, &GLookAtOpFixedSettings_t::SetUseHysteresis)
        .endClass();
}