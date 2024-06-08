class GC_INIT_CreateFromPlaneCache;

#ifndef _gcc_init_createfromplanecache_h
#define _gcc_init_createfromplanecache_h

#include "../../../scripting.h"




class GC_INIT_CreateFromPlaneCache
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateFromPlaneCache() {}
    GC_INIT_CreateFromPlaneCache(void *ptr) : m_ptr(ptr) {}

    Vector GetOffsetMin() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_CreateFromPlaneCache", "m_vecOffsetMin"); }
    void SetOffsetMin(Vector value) { SetSchemaValue(m_ptr, "C_INIT_CreateFromPlaneCache", "m_vecOffsetMin", false, value); }
    Vector GetOffsetMax() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_CreateFromPlaneCache", "m_vecOffsetMax"); }
    void SetOffsetMax(Vector value) { SetSchemaValue(m_ptr, "C_INIT_CreateFromPlaneCache", "m_vecOffsetMax", false, value); }
    bool GetUseNormal() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateFromPlaneCache", "m_bUseNormal"); }
    void SetUseNormal(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateFromPlaneCache", "m_bUseNormal", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif