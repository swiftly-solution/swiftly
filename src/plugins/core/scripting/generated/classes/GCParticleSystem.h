class GCParticleSystem;

#ifndef _gccparticlesystem_h
#define _gccparticlesystem_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCParticleSystem
{
private:
    void *m_ptr;

public:
    GCParticleSystem() {}
    GCParticleSystem(void *ptr) : m_ptr(ptr) {}

    std::string GetSnapshotFileName() const { return GetSchemaValue<char*>(m_ptr, "CParticleSystem", "m_szSnapshotFileName"); }
    void SetSnapshotFileName(std::string value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_szSnapshotFileName", false, value); }
    bool GetActive() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bActive"); }
    void SetActive(bool value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_bActive", false, value); }
    bool GetFrozen() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bFrozen"); }
    void SetFrozen(bool value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_bFrozen", false, value); }
    float GetFreezeTransitionDuration() const { return GetSchemaValue<float>(m_ptr, "CParticleSystem", "m_flFreezeTransitionDuration"); }
    void SetFreezeTransitionDuration(float value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_flFreezeTransitionDuration", false, value); }
    int32_t GetStopType() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystem", "m_nStopType"); }
    void SetStopType(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_nStopType", false, value); }
    bool GetAnimateDuringGameplayPause() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bAnimateDuringGameplayPause"); }
    void SetAnimateDuringGameplayPause(bool value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_bAnimateDuringGameplayPause", false, value); }
    float GetPreSimTime() const { return GetSchemaValue<float>(m_ptr, "CParticleSystem", "m_flPreSimTime"); }
    void SetPreSimTime(float value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_flPreSimTime", false, value); }
    std::vector<Vector> GetServerControlPoints() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CParticleSystem", "m_vServerControlPoints"); std::vector<Vector> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetServerControlPoints(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CParticleSystem", "m_vServerControlPoints"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CParticleSystem", "m_vServerControlPoints", false, outValue); }
    std::vector<uint8_t> GetServerControlPointAssignments() const { uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "CParticleSystem", "m_iServerControlPointAssignments"); std::vector<uint8_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetServerControlPointAssignments(std::vector<uint8_t> value) { uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "CParticleSystem", "m_iServerControlPointAssignments"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CParticleSystem", "m_iServerControlPointAssignments", false, outValue); }
    GCBaseEntity* GetControlPointEnts() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CParticleSystem", "m_hControlPointEnts"); }
    void SetControlPointEnts(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ControlPointEnts' is not possible.\n"); }
    bool GetNoSave() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bNoSave"); }
    void SetNoSave(bool value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_bNoSave", false, value); }
    bool GetNoFreeze() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bNoFreeze"); }
    void SetNoFreeze(bool value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_bNoFreeze", false, value); }
    bool GetNoRamp() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bNoRamp"); }
    void SetNoRamp(bool value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_bNoRamp", false, value); }
    bool GetStartActive() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bStartActive"); }
    void SetStartActive(bool value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_bStartActive", false, value); }
    CUtlSymbolLarge GetEffectName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CParticleSystem", "m_iszEffectName"); }
    void SetEffectName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_iszEffectName", false, value); }
    std::vector<CUtlSymbolLarge> GetControlPointNames() const { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CParticleSystem", "m_iszControlPointNames"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetControlPointNames(std::vector<CUtlSymbolLarge> value) { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CParticleSystem", "m_iszControlPointNames"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CParticleSystem", "m_iszControlPointNames", false, outValue); }
    int32_t GetDataCP() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystem", "m_nDataCP"); }
    void SetDataCP(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_nDataCP", false, value); }
    Vector GetDataCPValue() const { return GetSchemaValue<Vector>(m_ptr, "CParticleSystem", "m_vecDataCPValue"); }
    void SetDataCPValue(Vector value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_vecDataCPValue", false, value); }
    int32_t GetTintCP() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystem", "m_nTintCP"); }
    void SetTintCP(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_nTintCP", false, value); }
    Color GetTint() const { return GetSchemaValue<Color>(m_ptr, "CParticleSystem", "m_clrTint"); }
    void SetTint(Color value) { SetSchemaValue(m_ptr, "CParticleSystem", "m_clrTint", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif