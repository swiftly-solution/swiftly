class GRnShapeDesc_t;

#ifndef _gcrnshapedesc_t_h
#define _gcrnshapedesc_t_h

#include "../../../scripting.h"




class GRnShapeDesc_t
{
private:
    void *m_ptr;

public:
    GRnShapeDesc_t() {}
    GRnShapeDesc_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetCollisionAttributeIndex() const { return GetSchemaValue<uint32_t>(m_ptr, "RnShapeDesc_t", "m_nCollisionAttributeIndex"); }
    void SetCollisionAttributeIndex(uint32_t value) { SetSchemaValue(m_ptr, "RnShapeDesc_t", "m_nCollisionAttributeIndex", true, value); }
    uint32_t GetSurfacePropertyIndex() const { return GetSchemaValue<uint32_t>(m_ptr, "RnShapeDesc_t", "m_nSurfacePropertyIndex"); }
    void SetSurfacePropertyIndex(uint32_t value) { SetSchemaValue(m_ptr, "RnShapeDesc_t", "m_nSurfacePropertyIndex", true, value); }
    CUtlString GetUserFriendlyName() const { return GetSchemaValue<CUtlString>(m_ptr, "RnShapeDesc_t", "m_UserFriendlyName"); }
    void SetUserFriendlyName(CUtlString value) { SetSchemaValue(m_ptr, "RnShapeDesc_t", "m_UserFriendlyName", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif