class GCSoundOpvarSetAABBEntity;

#ifndef _gccsoundopvarsetaabbentity_h
#define _gccsoundopvarsetaabbentity_h

#include "../../../scripting.h"




class GCSoundOpvarSetAABBEntity
{
private:
    void *m_ptr;

public:
    GCSoundOpvarSetAABBEntity() {}
    GCSoundOpvarSetAABBEntity(void *ptr) : m_ptr(ptr) {}

    Vector GetDistanceInnerMins() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceInnerMins"); }
    void SetDistanceInnerMins(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceInnerMins", false, value); }
    Vector GetDistanceInnerMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceInnerMaxs"); }
    void SetDistanceInnerMaxs(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceInnerMaxs", false, value); }
    Vector GetDistanceOuterMins() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceOuterMins"); }
    void SetDistanceOuterMins(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceOuterMins", false, value); }
    Vector GetDistanceOuterMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceOuterMaxs"); }
    void SetDistanceOuterMaxs(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceOuterMaxs", false, value); }
    int32_t GetAABBDirection() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetAABBEntity", "m_nAABBDirection"); }
    void SetAABBDirection(int32_t value) { SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_nAABBDirection", false, value); }
    Vector GetInnerMins() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vInnerMins"); }
    void SetInnerMins(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vInnerMins", false, value); }
    Vector GetInnerMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vInnerMaxs"); }
    void SetInnerMaxs(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vInnerMaxs", false, value); }
    Vector GetOuterMins() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vOuterMins"); }
    void SetOuterMins(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vOuterMins", false, value); }
    Vector GetOuterMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vOuterMaxs"); }
    void SetOuterMaxs(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vOuterMaxs", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif