class GFeSourceEdge_t;

#ifndef _gcfesourceedge_t_h
#define _gcfesourceedge_t_h

#include "../../../scripting.h"




class GFeSourceEdge_t
{
private:
    void *m_ptr;

public:
    GFeSourceEdge_t() {}
    GFeSourceEdge_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint16_t> GetNode() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSourceEdge_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNode(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSourceEdge_t", "nNode"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSourceEdge_t", "nNode", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif