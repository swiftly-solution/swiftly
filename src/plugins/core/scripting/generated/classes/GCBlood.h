class GCBlood;

#ifndef _gccblood_h
#define _gccblood_h

#include "../../../scripting.h"

#include "../types/GBloodType.h"


class GCBlood
{
private:
    void *m_ptr;

public:
    GCBlood() {}
    GCBlood(void *ptr) : m_ptr(ptr) {}

    QAngle GetSprayAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CBlood", "m_vecSprayAngles"); }
    void SetSprayAngles(QAngle value) { SetSchemaValue(m_ptr, "CBlood", "m_vecSprayAngles", false, value); }
    Vector GetSprayDir() const { return GetSchemaValue<Vector>(m_ptr, "CBlood", "m_vecSprayDir"); }
    void SetSprayDir(Vector value) { SetSchemaValue(m_ptr, "CBlood", "m_vecSprayDir", false, value); }
    float GetAmount() const { return GetSchemaValue<float>(m_ptr, "CBlood", "m_flAmount"); }
    void SetAmount(float value) { SetSchemaValue(m_ptr, "CBlood", "m_flAmount", false, value); }
    BloodType GetColor() const { return GetSchemaValue<BloodType>(m_ptr, "CBlood", "m_Color"); }
    void SetColor(BloodType value) { SetSchemaValue(m_ptr, "CBlood", "m_Color", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif