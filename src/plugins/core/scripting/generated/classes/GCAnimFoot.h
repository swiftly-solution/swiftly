class GCAnimFoot;

#ifndef _gccanimfoot_h
#define _gccanimfoot_h

#include "../../../scripting.h"




class GCAnimFoot
{
private:
    void *m_ptr;

public:
    GCAnimFoot() {}
    GCAnimFoot(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CAnimFoot", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CAnimFoot", "m_name", false, value); }
    Vector GetBallOffset() const { return GetSchemaValue<Vector>(m_ptr, "CAnimFoot", "m_vBallOffset"); }
    void SetBallOffset(Vector value) { SetSchemaValue(m_ptr, "CAnimFoot", "m_vBallOffset", false, value); }
    Vector GetHeelOffset() const { return GetSchemaValue<Vector>(m_ptr, "CAnimFoot", "m_vHeelOffset"); }
    void SetHeelOffset(Vector value) { SetSchemaValue(m_ptr, "CAnimFoot", "m_vHeelOffset", false, value); }
    int32_t GetAnkleBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimFoot", "m_ankleBoneIndex"); }
    void SetAnkleBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "CAnimFoot", "m_ankleBoneIndex", false, value); }
    int32_t GetToeBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimFoot", "m_toeBoneIndex"); }
    void SetToeBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "CAnimFoot", "m_toeBoneIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif