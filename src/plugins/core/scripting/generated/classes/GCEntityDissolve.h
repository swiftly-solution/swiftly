class GCEntityDissolve;

#ifndef _gccentitydissolve_h
#define _gccentitydissolve_h

#include "../../../scripting.h"

#include "../types/GEntityDisolveType_t.h"


class GCEntityDissolve
{
private:
    void *m_ptr;

public:
    GCEntityDissolve() {}
    GCEntityDissolve(void *ptr) : m_ptr(ptr) {}

    float GetFadeInStart() const { return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flFadeInStart"); }
    void SetFadeInStart(float value) { SetSchemaValue(m_ptr, "CEntityDissolve", "m_flFadeInStart", false, value); }
    float GetFadeInLength() const { return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flFadeInLength"); }
    void SetFadeInLength(float value) { SetSchemaValue(m_ptr, "CEntityDissolve", "m_flFadeInLength", false, value); }
    float GetFadeOutModelStart() const { return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flFadeOutModelStart"); }
    void SetFadeOutModelStart(float value) { SetSchemaValue(m_ptr, "CEntityDissolve", "m_flFadeOutModelStart", false, value); }
    float GetFadeOutModelLength() const { return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flFadeOutModelLength"); }
    void SetFadeOutModelLength(float value) { SetSchemaValue(m_ptr, "CEntityDissolve", "m_flFadeOutModelLength", false, value); }
    float GetFadeOutStart() const { return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flFadeOutStart"); }
    void SetFadeOutStart(float value) { SetSchemaValue(m_ptr, "CEntityDissolve", "m_flFadeOutStart", false, value); }
    float GetFadeOutLength() const { return GetSchemaValue<float>(m_ptr, "CEntityDissolve", "m_flFadeOutLength"); }
    void SetFadeOutLength(float value) { SetSchemaValue(m_ptr, "CEntityDissolve", "m_flFadeOutLength", false, value); }
    EntityDisolveType_t GetDissolveType() const { return GetSchemaValue<EntityDisolveType_t>(m_ptr, "CEntityDissolve", "m_nDissolveType"); }
    void SetDissolveType(EntityDisolveType_t value) { SetSchemaValue(m_ptr, "CEntityDissolve", "m_nDissolveType", false, value); }
    Vector GetDissolverOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CEntityDissolve", "m_vDissolverOrigin"); }
    void SetDissolverOrigin(Vector value) { SetSchemaValue(m_ptr, "CEntityDissolve", "m_vDissolverOrigin", false, value); }
    uint32_t GetMagnitude() const { return GetSchemaValue<uint32_t>(m_ptr, "CEntityDissolve", "m_nMagnitude"); }
    void SetMagnitude(uint32_t value) { SetSchemaValue(m_ptr, "CEntityDissolve", "m_nMagnitude", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif