#include "../../../core/scripting/generated/classes/GAimMatrixOpFixedSettings_t.h"
#include "../core.h"

void SetupLuaClassGAimMatrixOpFixedSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAimMatrixOpFixedSettings_t>("AimMatrixOpFixedSettings_t")
        .addProperty("Attachment", &GAimMatrixOpFixedSettings_t::GetAttachment, &GAimMatrixOpFixedSettings_t::SetAttachment)
        .addProperty("Damping", &GAimMatrixOpFixedSettings_t::GetDamping, &GAimMatrixOpFixedSettings_t::SetDamping)
        .addProperty("PoseCacheHandles", &GAimMatrixOpFixedSettings_t::GetPoseCacheHandles, &GAimMatrixOpFixedSettings_t::SetPoseCacheHandles)
        .addProperty("BlendMode", &GAimMatrixOpFixedSettings_t::GetBlendMode, &GAimMatrixOpFixedSettings_t::SetBlendMode)
        .addProperty("MaxYawAngle", &GAimMatrixOpFixedSettings_t::GetMaxYawAngle, &GAimMatrixOpFixedSettings_t::SetMaxYawAngle)
        .addProperty("MaxPitchAngle", &GAimMatrixOpFixedSettings_t::GetMaxPitchAngle, &GAimMatrixOpFixedSettings_t::SetMaxPitchAngle)
        .addProperty("SequenceMaxFrame", &GAimMatrixOpFixedSettings_t::GetSequenceMaxFrame, &GAimMatrixOpFixedSettings_t::SetSequenceMaxFrame)
        .addProperty("BoneMaskIndex", &GAimMatrixOpFixedSettings_t::GetBoneMaskIndex, &GAimMatrixOpFixedSettings_t::SetBoneMaskIndex)
        .addProperty("TargetIsPosition", &GAimMatrixOpFixedSettings_t::GetTargetIsPosition, &GAimMatrixOpFixedSettings_t::SetTargetIsPosition)
        .addProperty("UseBiasAndClamp", &GAimMatrixOpFixedSettings_t::GetUseBiasAndClamp, &GAimMatrixOpFixedSettings_t::SetUseBiasAndClamp)
        .addProperty("BiasAndClampYawOffset", &GAimMatrixOpFixedSettings_t::GetBiasAndClampYawOffset, &GAimMatrixOpFixedSettings_t::SetBiasAndClampYawOffset)
        .addProperty("BiasAndClampPitchOffset", &GAimMatrixOpFixedSettings_t::GetBiasAndClampPitchOffset, &GAimMatrixOpFixedSettings_t::SetBiasAndClampPitchOffset)
        .addProperty("BiasAndClampBlendCurve", &GAimMatrixOpFixedSettings_t::GetBiasAndClampBlendCurve, &GAimMatrixOpFixedSettings_t::SetBiasAndClampBlendCurve)
        .endClass();
}