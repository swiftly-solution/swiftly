class GFeEdgeDesc_t;

#ifndef _gcfeedgedesc_t_h
#define _gcfeedgedesc_t_h

#include "../../../scripting.h"




class GFeEdgeDesc_t
{
private:
    void *m_ptr;

public:
    GFeEdgeDesc_t() {}
    GFeEdgeDesc_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint16_t> GetEdge() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeEdgeDesc_t", "nEdge"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetEdge(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeEdgeDesc_t", "nEdge"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeEdgeDesc_t", "nEdge", true, outValue); }
    std::vector<uint16_t> GetVirtElem() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeEdgeDesc_t", "nVirtElem"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetVirtElem(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeEdgeDesc_t", "nVirtElem"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeEdgeDesc_t", "nVirtElem", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif