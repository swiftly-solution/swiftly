class GFeTaperedCapsuleStretch_t;

#ifndef _gcfetaperedcapsulestretch_t_h
#define _gcfetaperedcapsulestretch_t_h

#include "../../../scripting.h"




class GFeTaperedCapsuleStretch_t
{
private:
    void *m_ptr;

public:
    GFeTaperedCapsuleStretch_t() {}
    GFeTaperedCapsuleStretch_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint16_t> GetNode() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeTaperedCapsuleStretch_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNode(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeTaperedCapsuleStretch_t", "nNode"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeTaperedCapsuleStretch_t", "nNode", true, outValue); }
    uint16_t GetCollisionMask() const { return GetSchemaValue<uint16_t>(m_ptr, "FeTaperedCapsuleStretch_t", "nCollisionMask"); }
    void SetCollisionMask(uint16_t value) { SetSchemaValue(m_ptr, "FeTaperedCapsuleStretch_t", "nCollisionMask", true, value); }
    uint16_t GetDummy() const { return GetSchemaValue<uint16_t>(m_ptr, "FeTaperedCapsuleStretch_t", "nDummy"); }
    void SetDummy(uint16_t value) { SetSchemaValue(m_ptr, "FeTaperedCapsuleStretch_t", "nDummy", true, value); }
    std::vector<float> GetRadius() const { float* outValue = GetSchemaValue<float*>(m_ptr, "FeTaperedCapsuleStretch_t", "flRadius"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetRadius(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "FeTaperedCapsuleStretch_t", "flRadius"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeTaperedCapsuleStretch_t", "flRadius", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif