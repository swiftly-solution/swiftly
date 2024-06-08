#include "../../../core/scripting/generated/classes/GCBeam.h"
#include "../core.h"

void SetupLuaClassGCBeam(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBeam>("CBeam")
        .addProperty("FrameRate", &GCBeam::GetFrameRate, &GCBeam::SetFrameRate)
        .addProperty("HDRColorScale", &GCBeam::GetHDRColorScale, &GCBeam::SetHDRColorScale)
        .addProperty("Damage", &GCBeam::GetDamage, &GCBeam::SetDamage)
        .addProperty("NumBeamEnts", &GCBeam::GetNumBeamEnts, &GCBeam::SetNumBeamEnts)
        .addProperty("BeamType", &GCBeam::GetBeamType, &GCBeam::SetBeamType)
        .addProperty("BeamFlags", &GCBeam::GetBeamFlags, &GCBeam::SetBeamFlags)
        .addProperty("AttachEntity", &GCBeam::GetAttachEntity, &GCBeam::SetAttachEntity)
        .addProperty("Width", &GCBeam::GetWidth, &GCBeam::SetWidth)
        .addProperty("EndWidth", &GCBeam::GetEndWidth, &GCBeam::SetEndWidth)
        .addProperty("FadeLength", &GCBeam::GetFadeLength, &GCBeam::SetFadeLength)
        .addProperty("HaloScale", &GCBeam::GetHaloScale, &GCBeam::SetHaloScale)
        .addProperty("Amplitude", &GCBeam::GetAmplitude, &GCBeam::SetAmplitude)
        .addProperty("StartFrame", &GCBeam::GetStartFrame, &GCBeam::SetStartFrame)
        .addProperty("Speed", &GCBeam::GetSpeed, &GCBeam::SetSpeed)
        .addProperty("Frame", &GCBeam::GetFrame, &GCBeam::SetFrame)
        .addProperty("ClipStyle", &GCBeam::GetClipStyle, &GCBeam::SetClipStyle)
        .addProperty("TurnedOff", &GCBeam::GetTurnedOff, &GCBeam::SetTurnedOff)
        .addProperty("EndPos", &GCBeam::GetEndPos, &GCBeam::SetEndPos)
        .addProperty("EndEntity", &GCBeam::GetEndEntity, &GCBeam::SetEndEntity)
        .addProperty("DissolveType", &GCBeam::GetDissolveType, &GCBeam::SetDissolveType)
        .endClass();
}