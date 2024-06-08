class GC_INIT_InitialVelocityFromHitbox;

#ifndef _gcc_init_initialvelocityfromhitbox_h
#define _gcc_init_initialvelocityfromhitbox_h

#include "../../../scripting.h"




class GC_INIT_InitialVelocityFromHitbox
{
private:
    void *m_ptr;

public:
    GC_INIT_InitialVelocityFromHitbox() {}
    GC_INIT_InitialVelocityFromHitbox(void *ptr) : m_ptr(ptr) {}

    float GetVelocityMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InitialVelocityFromHitbox", "m_flVelocityMin"); }
    void SetVelocityMin(float value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityFromHitbox", "m_flVelocityMin", false, value); }
    float GetVelocityMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InitialVelocityFromHitbox", "m_flVelocityMax"); }
    void SetVelocityMax(float value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityFromHitbox", "m_flVelocityMax", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitialVelocityFromHitbox", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityFromHitbox", "m_nControlPointNumber", false, value); }
    std::string GetHitboxSetName() const { return GetSchemaValue<char*>(m_ptr, "C_INIT_InitialVelocityFromHitbox", "m_HitboxSetName"); }
    void SetHitboxSetName(std::string value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityFromHitbox", "m_HitboxSetName", false, value); }
    bool GetUseBones() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitialVelocityFromHitbox", "m_bUseBones"); }
    void SetUseBones(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityFromHitbox", "m_bUseBones", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif