class GCPathParticleRope;

#ifndef _gccpathparticlerope_h
#define _gccpathparticlerope_h

#include "../../../scripting.h"




class GCPathParticleRope
{
private:
    void *m_ptr;

public:
    GCPathParticleRope() {}
    GCPathParticleRope(void *ptr) : m_ptr(ptr) {}

    bool GetStartActive() const { return GetSchemaValue<bool>(m_ptr, "CPathParticleRope", "m_bStartActive"); }
    void SetStartActive(bool value) { SetSchemaValue(m_ptr, "CPathParticleRope", "m_bStartActive", false, value); }
    float GetMaxSimulationTime() const { return GetSchemaValue<float>(m_ptr, "CPathParticleRope", "m_flMaxSimulationTime"); }
    void SetMaxSimulationTime(float value) { SetSchemaValue(m_ptr, "CPathParticleRope", "m_flMaxSimulationTime", false, value); }
    CUtlSymbolLarge GetEffectName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPathParticleRope", "m_iszEffectName"); }
    void SetEffectName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPathParticleRope", "m_iszEffectName", false, value); }
    std::vector<CUtlSymbolLarge> GetPathNodes_Name() const { CUtlVector<CUtlSymbolLarge>* vec = GetSchemaValue<CUtlVector<CUtlSymbolLarge>*>(m_ptr, "CPathParticleRope", "m_PathNodes_Name"); std::vector<CUtlSymbolLarge> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPathNodes_Name(std::vector<CUtlSymbolLarge> value) { SetSchemaValueCUtlVector<CUtlSymbolLarge>(m_ptr, "CPathParticleRope", "m_PathNodes_Name", false, value); }
    float GetParticleSpacing() const { return GetSchemaValue<float>(m_ptr, "CPathParticleRope", "m_flParticleSpacing"); }
    void SetParticleSpacing(float value) { SetSchemaValue(m_ptr, "CPathParticleRope", "m_flParticleSpacing", false, value); }
    float GetSlack() const { return GetSchemaValue<float>(m_ptr, "CPathParticleRope", "m_flSlack"); }
    void SetSlack(float value) { SetSchemaValue(m_ptr, "CPathParticleRope", "m_flSlack", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CPathParticleRope", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CPathParticleRope", "m_flRadius", false, value); }
    Color GetColorTint() const { return GetSchemaValue<Color>(m_ptr, "CPathParticleRope", "m_ColorTint"); }
    void SetColorTint(Color value) { SetSchemaValue(m_ptr, "CPathParticleRope", "m_ColorTint", false, value); }
    int32_t GetEffectState() const { return GetSchemaValue<int32_t>(m_ptr, "CPathParticleRope", "m_nEffectState"); }
    void SetEffectState(int32_t value) { SetSchemaValue(m_ptr, "CPathParticleRope", "m_nEffectState", false, value); }
    std::vector<Vector> GetPathNodes_Position() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CPathParticleRope", "m_PathNodes_Position"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPathNodes_Position(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CPathParticleRope", "m_PathNodes_Position", false, value); }
    std::vector<Vector> GetPathNodes_TangentIn() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CPathParticleRope", "m_PathNodes_TangentIn"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPathNodes_TangentIn(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CPathParticleRope", "m_PathNodes_TangentIn", false, value); }
    std::vector<Vector> GetPathNodes_TangentOut() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CPathParticleRope", "m_PathNodes_TangentOut"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPathNodes_TangentOut(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CPathParticleRope", "m_PathNodes_TangentOut", false, value); }
    std::vector<Vector> GetPathNodes_Color() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CPathParticleRope", "m_PathNodes_Color"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPathNodes_Color(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CPathParticleRope", "m_PathNodes_Color", false, value); }
    std::vector<bool> GetPathNodes_PinEnabled() const { CUtlVector<bool>* vec = GetSchemaValue<CUtlVector<bool>*>(m_ptr, "CPathParticleRope", "m_PathNodes_PinEnabled"); std::vector<bool> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPathNodes_PinEnabled(std::vector<bool> value) { SetSchemaValueCUtlVector<bool>(m_ptr, "CPathParticleRope", "m_PathNodes_PinEnabled", false, value); }
    std::vector<float32> GetPathNodes_RadiusScale() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CPathParticleRope", "m_PathNodes_RadiusScale"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPathNodes_RadiusScale(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CPathParticleRope", "m_PathNodes_RadiusScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif