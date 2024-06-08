class GCBeam;

#ifndef _gccbeam_h
#define _gccbeam_h

#include "../../../scripting.h"

#include "../types/GBeamType_t.h"
#include "../types/GBeamClipStyle_t.h"
#include "GCBaseEntity.h"

class GCBeam
{
private:
    void *m_ptr;

public:
    GCBeam() {}
    GCBeam(void *ptr) : m_ptr(ptr) {}

    float GetFrameRate() const { return GetSchemaValue<float>(m_ptr, "CBeam", "m_flFrameRate"); }
    void SetFrameRate(float value) { SetSchemaValue(m_ptr, "CBeam", "m_flFrameRate", false, value); }
    float GetHDRColorScale() const { return GetSchemaValue<float>(m_ptr, "CBeam", "m_flHDRColorScale"); }
    void SetHDRColorScale(float value) { SetSchemaValue(m_ptr, "CBeam", "m_flHDRColorScale", false, value); }
    float GetDamage() const { return GetSchemaValue<float>(m_ptr, "CBeam", "m_flDamage"); }
    void SetDamage(float value) { SetSchemaValue(m_ptr, "CBeam", "m_flDamage", false, value); }
    uint8_t GetNumBeamEnts() const { return GetSchemaValue<uint8_t>(m_ptr, "CBeam", "m_nNumBeamEnts"); }
    void SetNumBeamEnts(uint8_t value) { SetSchemaValue(m_ptr, "CBeam", "m_nNumBeamEnts", false, value); }
    BeamType_t GetBeamType() const { return GetSchemaValue<BeamType_t>(m_ptr, "CBeam", "m_nBeamType"); }
    void SetBeamType(BeamType_t value) { SetSchemaValue(m_ptr, "CBeam", "m_nBeamType", false, value); }
    uint32_t GetBeamFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "CBeam", "m_nBeamFlags"); }
    void SetBeamFlags(uint32_t value) { SetSchemaValue(m_ptr, "CBeam", "m_nBeamFlags", false, value); }
    GCBaseEntity* GetAttachEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBeam", "m_hAttachEntity"); }
    void SetAttachEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'AttachEntity' is not possible.\n"); }
    float GetWidth() const { return GetSchemaValue<float>(m_ptr, "CBeam", "m_fWidth"); }
    void SetWidth(float value) { SetSchemaValue(m_ptr, "CBeam", "m_fWidth", false, value); }
    float GetEndWidth() const { return GetSchemaValue<float>(m_ptr, "CBeam", "m_fEndWidth"); }
    void SetEndWidth(float value) { SetSchemaValue(m_ptr, "CBeam", "m_fEndWidth", false, value); }
    float GetFadeLength() const { return GetSchemaValue<float>(m_ptr, "CBeam", "m_fFadeLength"); }
    void SetFadeLength(float value) { SetSchemaValue(m_ptr, "CBeam", "m_fFadeLength", false, value); }
    float GetHaloScale() const { return GetSchemaValue<float>(m_ptr, "CBeam", "m_fHaloScale"); }
    void SetHaloScale(float value) { SetSchemaValue(m_ptr, "CBeam", "m_fHaloScale", false, value); }
    float GetAmplitude() const { return GetSchemaValue<float>(m_ptr, "CBeam", "m_fAmplitude"); }
    void SetAmplitude(float value) { SetSchemaValue(m_ptr, "CBeam", "m_fAmplitude", false, value); }
    float GetStartFrame() const { return GetSchemaValue<float>(m_ptr, "CBeam", "m_fStartFrame"); }
    void SetStartFrame(float value) { SetSchemaValue(m_ptr, "CBeam", "m_fStartFrame", false, value); }
    float GetSpeed() const { return GetSchemaValue<float>(m_ptr, "CBeam", "m_fSpeed"); }
    void SetSpeed(float value) { SetSchemaValue(m_ptr, "CBeam", "m_fSpeed", false, value); }
    float GetFrame() const { return GetSchemaValue<float>(m_ptr, "CBeam", "m_flFrame"); }
    void SetFrame(float value) { SetSchemaValue(m_ptr, "CBeam", "m_flFrame", false, value); }
    BeamClipStyle_t GetClipStyle() const { return GetSchemaValue<BeamClipStyle_t>(m_ptr, "CBeam", "m_nClipStyle"); }
    void SetClipStyle(BeamClipStyle_t value) { SetSchemaValue(m_ptr, "CBeam", "m_nClipStyle", false, value); }
    bool GetTurnedOff() const { return GetSchemaValue<bool>(m_ptr, "CBeam", "m_bTurnedOff"); }
    void SetTurnedOff(bool value) { SetSchemaValue(m_ptr, "CBeam", "m_bTurnedOff", false, value); }
    Vector GetEndPos() const { return GetSchemaValue<Vector>(m_ptr, "CBeam", "m_vecEndPos"); }
    void SetEndPos(Vector value) { SetSchemaValue(m_ptr, "CBeam", "m_vecEndPos", false, value); }
    GCBaseEntity* GetEndEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBeam", "m_hEndEntity"); }
    void SetEndEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'EndEntity' is not possible.\n"); }
    int32_t GetDissolveType() const { return GetSchemaValue<int32_t>(m_ptr, "CBeam", "m_nDissolveType"); }
    void SetDissolveType(int32_t value) { SetSchemaValue(m_ptr, "CBeam", "m_nDissolveType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif