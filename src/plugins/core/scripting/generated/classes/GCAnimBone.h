class GCAnimBone;

#ifndef _gccanimbone_h
#define _gccanimbone_h

#include "../../../scripting.h"




class GCAnimBone
{
private:
    void *m_ptr;

public:
    GCAnimBone() {}
    GCAnimBone(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimBone", "m_name"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimBone", "m_name", false, value); }
    int32_t GetParent() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimBone", "m_parent"); }
    void SetParent(int32_t value) { SetSchemaValue(m_ptr, "CAnimBone", "m_parent", false, value); }
    Vector GetPos() const { return GetSchemaValue<Vector>(m_ptr, "CAnimBone", "m_pos"); }
    void SetPos(Vector value) { SetSchemaValue(m_ptr, "CAnimBone", "m_pos", false, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "CAnimBone", "m_scale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "CAnimBone", "m_scale", false, value); }
    int32_t GetFlags() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimBone", "m_flags"); }
    void SetFlags(int32_t value) { SetSchemaValue(m_ptr, "CAnimBone", "m_flags", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif