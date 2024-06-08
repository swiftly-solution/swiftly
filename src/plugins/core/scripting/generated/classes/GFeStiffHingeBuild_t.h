class GFeStiffHingeBuild_t;

#ifndef _gcfestiffhingebuild_t_h
#define _gcfestiffhingebuild_t_h

#include "../../../scripting.h"




class GFeStiffHingeBuild_t
{
private:
    void *m_ptr;

public:
    GFeStiffHingeBuild_t() {}
    GFeStiffHingeBuild_t(void *ptr) : m_ptr(ptr) {}

    float GetMaxAngle() const { return GetSchemaValue<float>(m_ptr, "FeStiffHingeBuild_t", "flMaxAngle"); }
    void SetMaxAngle(float value) { SetSchemaValue(m_ptr, "FeStiffHingeBuild_t", "flMaxAngle", true, value); }
    float GetStrength() const { return GetSchemaValue<float>(m_ptr, "FeStiffHingeBuild_t", "flStrength"); }
    void SetStrength(float value) { SetSchemaValue(m_ptr, "FeStiffHingeBuild_t", "flStrength", true, value); }
    std::vector<float> GetMotionBias() const { float* outValue = GetSchemaValue<float*>(m_ptr, "FeStiffHingeBuild_t", "flMotionBias"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetMotionBias(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "FeStiffHingeBuild_t", "flMotionBias"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeStiffHingeBuild_t", "flMotionBias", true, outValue); }
    std::vector<uint16_t> GetNode() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeStiffHingeBuild_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNode(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeStiffHingeBuild_t", "nNode"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeStiffHingeBuild_t", "nNode", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif