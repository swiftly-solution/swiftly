class GCSoundOpvarSetOBBWindEntity;

#ifndef _gccsoundopvarsetobbwindentity_h
#define _gccsoundopvarsetobbwindentity_h

#include "../../../scripting.h"




class GCSoundOpvarSetOBBWindEntity
{
private:
    void *m_ptr;

public:
    GCSoundOpvarSetOBBWindEntity() {}
    GCSoundOpvarSetOBBWindEntity(void *ptr) : m_ptr(ptr) {}

    Vector GetMins() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vMins"); }
    void SetMins(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vMins", false, value); }
    Vector GetMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vMaxs"); }
    void SetMaxs(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vMaxs", false, value); }
    Vector GetDistanceMins() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vDistanceMins"); }
    void SetDistanceMins(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vDistanceMins", false, value); }
    Vector GetDistanceMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vDistanceMaxs"); }
    void SetDistanceMaxs(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vDistanceMaxs", false, value); }
    float GetWindMin() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMin"); }
    void SetWindMin(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMin", false, value); }
    float GetWindMax() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMax"); }
    void SetWindMax(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMax", false, value); }
    float GetWindMapMin() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMapMin"); }
    void SetWindMapMin(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMapMin", false, value); }
    float GetWindMapMax() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMapMax"); }
    void SetWindMapMax(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMapMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif