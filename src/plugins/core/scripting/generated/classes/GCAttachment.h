class GCAttachment;

#ifndef _gccattachment_h
#define _gccattachment_h

#include "../../../scripting.h"




class GCAttachment
{
private:
    void *m_ptr;

public:
    GCAttachment() {}
    GCAttachment(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CAttachment", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CAttachment", "m_name", false, value); }
    std::vector<CUtlString> GetInfluenceNames() const { CUtlString* outValue = GetSchemaValue<CUtlString*>(m_ptr, "CAttachment", "m_influenceNames"); std::vector<CUtlString> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetInfluenceNames(std::vector<CUtlString> value) { CUtlString* outValue = GetSchemaValue<CUtlString*>(m_ptr, "CAttachment", "m_influenceNames"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAttachment", "m_influenceNames", false, outValue); }
    std::vector<Quaternion> GetInfluenceRotations() const { Quaternion* outValue = GetSchemaValue<Quaternion*>(m_ptr, "CAttachment", "m_vInfluenceRotations"); std::vector<Quaternion> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetInfluenceRotations(std::vector<Quaternion> value) { Quaternion* outValue = GetSchemaValue<Quaternion*>(m_ptr, "CAttachment", "m_vInfluenceRotations"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAttachment", "m_vInfluenceRotations", false, outValue); }
    std::vector<Vector> GetInfluenceOffsets() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CAttachment", "m_vInfluenceOffsets"); std::vector<Vector> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetInfluenceOffsets(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CAttachment", "m_vInfluenceOffsets"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAttachment", "m_vInfluenceOffsets", false, outValue); }
    std::vector<float> GetInfluenceWeights() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CAttachment", "m_influenceWeights"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetInfluenceWeights(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CAttachment", "m_influenceWeights"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAttachment", "m_influenceWeights", false, outValue); }
    std::vector<bool> GetInfluenceRootTransform() const { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CAttachment", "m_bInfluenceRootTransform"); std::vector<bool> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetInfluenceRootTransform(std::vector<bool> value) { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CAttachment", "m_bInfluenceRootTransform"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAttachment", "m_bInfluenceRootTransform", false, outValue); }
    uint8_t GetInfluences() const { return GetSchemaValue<uint8_t>(m_ptr, "CAttachment", "m_nInfluences"); }
    void SetInfluences(uint8_t value) { SetSchemaValue(m_ptr, "CAttachment", "m_nInfluences", false, value); }
    bool GetIgnoreRotation() const { return GetSchemaValue<bool>(m_ptr, "CAttachment", "m_bIgnoreRotation"); }
    void SetIgnoreRotation(bool value) { SetSchemaValue(m_ptr, "CAttachment", "m_bIgnoreRotation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif