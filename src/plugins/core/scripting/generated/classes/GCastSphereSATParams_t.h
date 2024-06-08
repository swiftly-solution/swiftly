class GCastSphereSATParams_t;

#ifndef _gccastspheresatparams_t_h
#define _gccastspheresatparams_t_h

#include "../../../scripting.h"

#include "../types/GHull_t.h"
#include "GRnHull_t.h"

class GCastSphereSATParams_t
{
private:
    void *m_ptr;

public:
    GCastSphereSATParams_t() {}
    GCastSphereSATParams_t(void *ptr) : m_ptr(ptr) {}

    Vector GetRayStart() const { return GetSchemaValue<Vector>(m_ptr, "CastSphereSATParams_t", "m_vRayStart"); }
    void SetRayStart(Vector value) { SetSchemaValue(m_ptr, "CastSphereSATParams_t", "m_vRayStart", true, value); }
    Vector GetRayDelta() const { return GetSchemaValue<Vector>(m_ptr, "CastSphereSATParams_t", "m_vRayDelta"); }
    void SetRayDelta(Vector value) { SetSchemaValue(m_ptr, "CastSphereSATParams_t", "m_vRayDelta", true, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CastSphereSATParams_t", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CastSphereSATParams_t", "m_flRadius", true, value); }
    float GetMaxFraction() const { return GetSchemaValue<float>(m_ptr, "CastSphereSATParams_t", "m_flMaxFraction"); }
    void SetMaxFraction(float value) { SetSchemaValue(m_ptr, "CastSphereSATParams_t", "m_flMaxFraction", true, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "CastSphereSATParams_t", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "CastSphereSATParams_t", "m_flScale", true, value); }
    GRnHull_t* GetHull() const { return GetSchemaValue<GRnHull_t*>(m_ptr, "CastSphereSATParams_t", "m_pHull"); }
    void SetHull(GRnHull_t* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Hull' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif