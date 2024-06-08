class GRnHalfEdge_t;

#ifndef _gcrnhalfedge_t_h
#define _gcrnhalfedge_t_h

#include "../../../scripting.h"




class GRnHalfEdge_t
{
private:
    void *m_ptr;

public:
    GRnHalfEdge_t() {}
    GRnHalfEdge_t(void *ptr) : m_ptr(ptr) {}

    uint8_t GetNext() const { return GetSchemaValue<uint8_t>(m_ptr, "RnHalfEdge_t", "m_nNext"); }
    void SetNext(uint8_t value) { SetSchemaValue(m_ptr, "RnHalfEdge_t", "m_nNext", true, value); }
    uint8_t GetTwin() const { return GetSchemaValue<uint8_t>(m_ptr, "RnHalfEdge_t", "m_nTwin"); }
    void SetTwin(uint8_t value) { SetSchemaValue(m_ptr, "RnHalfEdge_t", "m_nTwin", true, value); }
    uint8_t GetOrigin() const { return GetSchemaValue<uint8_t>(m_ptr, "RnHalfEdge_t", "m_nOrigin"); }
    void SetOrigin(uint8_t value) { SetSchemaValue(m_ptr, "RnHalfEdge_t", "m_nOrigin", true, value); }
    uint8_t GetFace() const { return GetSchemaValue<uint8_t>(m_ptr, "RnHalfEdge_t", "m_nFace"); }
    void SetFace(uint8_t value) { SetSchemaValue(m_ptr, "RnHalfEdge_t", "m_nFace", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif