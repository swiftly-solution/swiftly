class GCSeqMultiFetchFlag;

#ifndef _gccseqmultifetchflag_h
#define _gccseqmultifetchflag_h

#include "../../../scripting.h"




class GCSeqMultiFetchFlag
{
private:
    void *m_ptr;

public:
    GCSeqMultiFetchFlag() {}
    GCSeqMultiFetchFlag(void *ptr) : m_ptr(ptr) {}

    bool GetRealtime() const { return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetchFlag", "m_bRealtime"); }
    void SetRealtime(bool value) { SetSchemaValue(m_ptr, "CSeqMultiFetchFlag", "m_bRealtime", false, value); }
    bool GetCylepose() const { return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetchFlag", "m_bCylepose"); }
    void SetCylepose(bool value) { SetSchemaValue(m_ptr, "CSeqMultiFetchFlag", "m_bCylepose", false, value); }
    bool Get0D() const { return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetchFlag", "m_b0D"); }
    void Set0D(bool value) { SetSchemaValue(m_ptr, "CSeqMultiFetchFlag", "m_b0D", false, value); }
    bool Get1D() const { return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetchFlag", "m_b1D"); }
    void Set1D(bool value) { SetSchemaValue(m_ptr, "CSeqMultiFetchFlag", "m_b1D", false, value); }
    bool Get2D() const { return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetchFlag", "m_b2D"); }
    void Set2D(bool value) { SetSchemaValue(m_ptr, "CSeqMultiFetchFlag", "m_b2D", false, value); }
    bool Get2D_TRI() const { return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetchFlag", "m_b2D_TRI"); }
    void Set2D_TRI(bool value) { SetSchemaValue(m_ptr, "CSeqMultiFetchFlag", "m_b2D_TRI", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif