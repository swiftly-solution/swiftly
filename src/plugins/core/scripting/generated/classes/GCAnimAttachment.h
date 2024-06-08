class GCAnimAttachment;

#ifndef _gccanimattachment_h
#define _gccanimattachment_h

#include "../../../scripting.h"




class GCAnimAttachment
{
private:
    void *m_ptr;

public:
    GCAnimAttachment() {}
    GCAnimAttachment(void *ptr) : m_ptr(ptr) {}

    std::vector<Quaternion> GetInfluenceRotations() const { Quaternion* outValue = GetSchemaValue<Quaternion*>(m_ptr, "CAnimAttachment", "m_influenceRotations"); std::vector<Quaternion> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetInfluenceRotations(std::vector<Quaternion> value) { Quaternion* outValue = GetSchemaValue<Quaternion*>(m_ptr, "CAnimAttachment", "m_influenceRotations"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAnimAttachment", "m_influenceRotations", false, outValue); }
    std::vector<Vector> GetInfluenceOffsets() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CAnimAttachment", "m_influenceOffsets"); std::vector<Vector> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetInfluenceOffsets(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CAnimAttachment", "m_influenceOffsets"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAnimAttachment", "m_influenceOffsets", false, outValue); }
    std::vector<int32_t> GetInfluenceIndices() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CAnimAttachment", "m_influenceIndices"); std::vector<int32_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetInfluenceIndices(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CAnimAttachment", "m_influenceIndices"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAnimAttachment", "m_influenceIndices", false, outValue); }
    std::vector<float> GetInfluenceWeights() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CAnimAttachment", "m_influenceWeights"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetInfluenceWeights(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CAnimAttachment", "m_influenceWeights"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAnimAttachment", "m_influenceWeights", false, outValue); }
    uint8_t GetNumInfluences() const { return GetSchemaValue<uint8_t>(m_ptr, "CAnimAttachment", "m_numInfluences"); }
    void SetNumInfluences(uint8_t value) { SetSchemaValue(m_ptr, "CAnimAttachment", "m_numInfluences", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif