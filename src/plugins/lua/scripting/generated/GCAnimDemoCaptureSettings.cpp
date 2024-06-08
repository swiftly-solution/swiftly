#include "../../../core/scripting/generated/classes/GCAnimDemoCaptureSettings.h"
#include "../core.h"

void SetupLuaClassGCAnimDemoCaptureSettings(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimDemoCaptureSettings>("CAnimDemoCaptureSettings")
        .addProperty("ErrorRangeSplineRotation", &GCAnimDemoCaptureSettings::GetErrorRangeSplineRotation, &GCAnimDemoCaptureSettings::SetErrorRangeSplineRotation)
        .addProperty("ErrorRangeSplineTranslation", &GCAnimDemoCaptureSettings::GetErrorRangeSplineTranslation, &GCAnimDemoCaptureSettings::SetErrorRangeSplineTranslation)
        .addProperty("ErrorRangeSplineScale", &GCAnimDemoCaptureSettings::GetErrorRangeSplineScale, &GCAnimDemoCaptureSettings::SetErrorRangeSplineScale)
        .addProperty("IkRotation_MaxSplineError", &GCAnimDemoCaptureSettings::GetIkRotation_MaxSplineError, &GCAnimDemoCaptureSettings::SetIkRotation_MaxSplineError)
        .addProperty("IkTranslation_MaxSplineError", &GCAnimDemoCaptureSettings::GetIkTranslation_MaxSplineError, &GCAnimDemoCaptureSettings::SetIkTranslation_MaxSplineError)
        .addProperty("ErrorRangeQuantizationRotation", &GCAnimDemoCaptureSettings::GetErrorRangeQuantizationRotation, &GCAnimDemoCaptureSettings::SetErrorRangeQuantizationRotation)
        .addProperty("ErrorRangeQuantizationTranslation", &GCAnimDemoCaptureSettings::GetErrorRangeQuantizationTranslation, &GCAnimDemoCaptureSettings::SetErrorRangeQuantizationTranslation)
        .addProperty("ErrorRangeQuantizationScale", &GCAnimDemoCaptureSettings::GetErrorRangeQuantizationScale, &GCAnimDemoCaptureSettings::SetErrorRangeQuantizationScale)
        .addProperty("IkRotation_MaxQuantizationError", &GCAnimDemoCaptureSettings::GetIkRotation_MaxQuantizationError, &GCAnimDemoCaptureSettings::SetIkRotation_MaxQuantizationError)
        .addProperty("IkTranslation_MaxQuantizationError", &GCAnimDemoCaptureSettings::GetIkTranslation_MaxQuantizationError, &GCAnimDemoCaptureSettings::SetIkTranslation_MaxQuantizationError)
        .addProperty("BaseSequence", &GCAnimDemoCaptureSettings::GetBaseSequence, &GCAnimDemoCaptureSettings::SetBaseSequence)
        .addProperty("BaseSequenceFrame", &GCAnimDemoCaptureSettings::GetBaseSequenceFrame, &GCAnimDemoCaptureSettings::SetBaseSequenceFrame)
        .addProperty("BoneSelectionMode", &GCAnimDemoCaptureSettings::GetBoneSelectionMode, &GCAnimDemoCaptureSettings::SetBoneSelectionMode)
        .addProperty("Bones", &GCAnimDemoCaptureSettings::GetBones, &GCAnimDemoCaptureSettings::SetBones)
        .addProperty("IkChains", &GCAnimDemoCaptureSettings::GetIkChains, &GCAnimDemoCaptureSettings::SetIkChains)
        .endClass();
}