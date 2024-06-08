class GCAnimDesc_Flag;

#ifndef _gccanimdesc_flag_h
#define _gccanimdesc_flag_h

#include "../../../scripting.h"




class GCAnimDesc_Flag
{
private:
    void *m_ptr;

public:
    GCAnimDesc_Flag() {}
    GCAnimDesc_Flag(void *ptr) : m_ptr(ptr) {}

    bool GetLooping() const { return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bLooping"); }
    void SetLooping(bool value) { SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bLooping", false, value); }
    bool GetAllZeros() const { return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bAllZeros"); }
    void SetAllZeros(bool value) { SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bAllZeros", false, value); }
    bool GetHidden() const { return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bHidden"); }
    void SetHidden(bool value) { SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bHidden", false, value); }
    bool GetDelta() const { return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bDelta"); }
    void SetDelta(bool value) { SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bDelta", false, value); }
    bool GetLegacyWorldspace() const { return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bLegacyWorldspace"); }
    void SetLegacyWorldspace(bool value) { SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bLegacyWorldspace", false, value); }
    bool GetModelDoc() const { return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bModelDoc"); }
    void SetModelDoc(bool value) { SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bModelDoc", false, value); }
    bool GetImplicitSeqIgnoreDelta() const { return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bImplicitSeqIgnoreDelta"); }
    void SetImplicitSeqIgnoreDelta(bool value) { SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bImplicitSeqIgnoreDelta", false, value); }
    bool GetAnimGraphAdditive() const { return GetSchemaValue<bool>(m_ptr, "CAnimDesc_Flag", "m_bAnimGraphAdditive"); }
    void SetAnimGraphAdditive(bool value) { SetSchemaValue(m_ptr, "CAnimDesc_Flag", "m_bAnimGraphAdditive", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif