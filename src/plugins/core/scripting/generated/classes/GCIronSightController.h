class GCIronSightController;

#ifndef _gccironsightcontroller_h
#define _gccironsightcontroller_h

#include "../../../scripting.h"




class GCIronSightController
{
private:
    void *m_ptr;

public:
    GCIronSightController() {}
    GCIronSightController(void *ptr) : m_ptr(ptr) {}

    bool GetIronSightAvailable() const { return GetSchemaValue<bool>(m_ptr, "CIronSightController", "m_bIronSightAvailable"); }
    void SetIronSightAvailable(bool value) { SetSchemaValue(m_ptr, "CIronSightController", "m_bIronSightAvailable", false, value); }
    float GetIronSightAmount() const { return GetSchemaValue<float>(m_ptr, "CIronSightController", "m_flIronSightAmount"); }
    void SetIronSightAmount(float value) { SetSchemaValue(m_ptr, "CIronSightController", "m_flIronSightAmount", false, value); }
    float GetIronSightAmountGained() const { return GetSchemaValue<float>(m_ptr, "CIronSightController", "m_flIronSightAmountGained"); }
    void SetIronSightAmountGained(float value) { SetSchemaValue(m_ptr, "CIronSightController", "m_flIronSightAmountGained", false, value); }
    float GetIronSightAmountBiased() const { return GetSchemaValue<float>(m_ptr, "CIronSightController", "m_flIronSightAmountBiased"); }
    void SetIronSightAmountBiased(float value) { SetSchemaValue(m_ptr, "CIronSightController", "m_flIronSightAmountBiased", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif