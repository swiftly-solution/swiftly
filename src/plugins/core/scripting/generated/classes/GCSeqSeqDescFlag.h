class GCSeqSeqDescFlag;

#ifndef _gccseqseqdescflag_h
#define _gccseqseqdescflag_h

#include "../../../scripting.h"




class GCSeqSeqDescFlag
{
private:
    void *m_ptr;

public:
    GCSeqSeqDescFlag() {}
    GCSeqSeqDescFlag(void *ptr) : m_ptr(ptr) {}

    bool GetLooping() const { return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bLooping"); }
    void SetLooping(bool value) { SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bLooping", false, value); }
    bool GetSnap() const { return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bSnap"); }
    void SetSnap(bool value) { SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bSnap", false, value); }
    bool GetAutoplay() const { return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bAutoplay"); }
    void SetAutoplay(bool value) { SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bAutoplay", false, value); }
    bool GetPost() const { return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bPost"); }
    void SetPost(bool value) { SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bPost", false, value); }
    bool GetHidden() const { return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bHidden"); }
    void SetHidden(bool value) { SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bHidden", false, value); }
    bool GetMulti() const { return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bMulti"); }
    void SetMulti(bool value) { SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bMulti", false, value); }
    bool GetLegacyDelta() const { return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bLegacyDelta"); }
    void SetLegacyDelta(bool value) { SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bLegacyDelta", false, value); }
    bool GetLegacyWorldspace() const { return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bLegacyWorldspace"); }
    void SetLegacyWorldspace(bool value) { SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bLegacyWorldspace", false, value); }
    bool GetLegacyCyclepose() const { return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bLegacyCyclepose"); }
    void SetLegacyCyclepose(bool value) { SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bLegacyCyclepose", false, value); }
    bool GetLegacyRealtime() const { return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bLegacyRealtime"); }
    void SetLegacyRealtime(bool value) { SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bLegacyRealtime", false, value); }
    bool GetModelDoc() const { return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bModelDoc"); }
    void SetModelDoc(bool value) { SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bModelDoc", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif