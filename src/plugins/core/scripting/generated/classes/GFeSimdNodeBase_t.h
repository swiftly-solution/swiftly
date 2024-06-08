class GFeSimdNodeBase_t;

#ifndef _gcfesimdnodebase_t_h
#define _gcfesimdnodebase_t_h

#include "../../../scripting.h"


#include "GFourQuaternions.h"

class GFeSimdNodeBase_t
{
private:
    void *m_ptr;

public:
    GFeSimdNodeBase_t() {}
    GFeSimdNodeBase_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint16_t> GetNode() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNode(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNode"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "nNode", true, outValue); }
    std::vector<uint16_t> GetNodeX0() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeX0"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNodeX0(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeX0"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "nNodeX0", true, outValue); }
    std::vector<uint16_t> GetNodeX1() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeX1"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNodeX1(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeX1"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "nNodeX1", true, outValue); }
    std::vector<uint16_t> GetNodeY0() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeY0"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNodeY0(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeY0"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "nNodeY0", true, outValue); }
    std::vector<uint16_t> GetNodeY1() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeY1"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNodeY1(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeY1"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "nNodeY1", true, outValue); }
    std::vector<uint16_t> GetDummy() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nDummy"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetDummy(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nDummy"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "nDummy", true, outValue); }
    GFourQuaternions GetAdjust() const { return GetSchemaValue<GFourQuaternions>(m_ptr, "FeSimdNodeBase_t", "qAdjust"); }
    void SetAdjust(GFourQuaternions value) { SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "qAdjust", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif