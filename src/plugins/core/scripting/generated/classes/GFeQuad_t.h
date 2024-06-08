class GFeQuad_t;

#ifndef _gcfequad_t_h
#define _gcfequad_t_h

#include "../../../scripting.h"




class GFeQuad_t
{
private:
    void *m_ptr;

public:
    GFeQuad_t() {}
    GFeQuad_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint16_t> GetNode() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeQuad_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNode(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeQuad_t", "nNode"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeQuad_t", "nNode", true, outValue); }
    float GetSlack() const { return GetSchemaValue<float>(m_ptr, "FeQuad_t", "flSlack"); }
    void SetSlack(float value) { SetSchemaValue(m_ptr, "FeQuad_t", "flSlack", true, value); }
    std::vector<Vector4D> GetShape() const { Vector4D* outValue = GetSchemaValue<Vector4D*>(m_ptr, "FeQuad_t", "vShape"); std::vector<Vector4D> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetShape(std::vector<Vector4D> value) { Vector4D* outValue = GetSchemaValue<Vector4D*>(m_ptr, "FeQuad_t", "vShape"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeQuad_t", "vShape", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif