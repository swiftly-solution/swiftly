class GC_INIT_SequenceFromCP;

#ifndef _gcc_init_sequencefromcp_h
#define _gcc_init_sequencefromcp_h

#include "../../../scripting.h"




class GC_INIT_SequenceFromCP
{
private:
    void *m_ptr;

public:
    GC_INIT_SequenceFromCP() {}
    GC_INIT_SequenceFromCP(void *ptr) : m_ptr(ptr) {}

    bool GetKillUnused() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_SequenceFromCP", "m_bKillUnused"); }
    void SetKillUnused(bool value) { SetSchemaValue(m_ptr, "C_INIT_SequenceFromCP", "m_bKillUnused", false, value); }
    bool GetRadiusScale() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_SequenceFromCP", "m_bRadiusScale"); }
    void SetRadiusScale(bool value) { SetSchemaValue(m_ptr, "C_INIT_SequenceFromCP", "m_bRadiusScale", false, value); }
    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_SequenceFromCP", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_SequenceFromCP", "m_nCP", false, value); }
    Vector GetOffset() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_SequenceFromCP", "m_vecOffset"); }
    void SetOffset(Vector value) { SetSchemaValue(m_ptr, "C_INIT_SequenceFromCP", "m_vecOffset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif