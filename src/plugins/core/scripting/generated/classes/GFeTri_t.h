class GFeTri_t;

#ifndef _gcfetri_t_h
#define _gcfetri_t_h

#include "../../../scripting.h"




class GFeTri_t
{
private:
    void *m_ptr;

public:
    GFeTri_t() {}
    GFeTri_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint16_t> GetNode() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeTri_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNode(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeTri_t", "nNode"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeTri_t", "nNode", true, outValue); }
    float GetW1() const { return GetSchemaValue<float>(m_ptr, "FeTri_t", "w1"); }
    void SetW1(float value) { SetSchemaValue(m_ptr, "FeTri_t", "w1", true, value); }
    float GetW2() const { return GetSchemaValue<float>(m_ptr, "FeTri_t", "w2"); }
    void SetW2(float value) { SetSchemaValue(m_ptr, "FeTri_t", "w2", true, value); }
    float Get1x() const { return GetSchemaValue<float>(m_ptr, "FeTri_t", "v1x"); }
    void Set1x(float value) { SetSchemaValue(m_ptr, "FeTri_t", "v1x", true, value); }
    Vector2D Get2() const { return GetSchemaValue<Vector2D>(m_ptr, "FeTri_t", "v2"); }
    void Set2(Vector2D value) { SetSchemaValue(m_ptr, "FeTri_t", "v2", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif