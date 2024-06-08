class GC_IronSightController;

#ifndef _gcc_ironsightcontroller_h
#define _gcc_ironsightcontroller_h

#include "../../../scripting.h"




class GC_IronSightController
{
private:
    void *m_ptr;

public:
    GC_IronSightController() {}
    GC_IronSightController(void *ptr) : m_ptr(ptr) {}

    bool GetIronSightAvailable() const { return GetSchemaValue<bool>(m_ptr, "C_IronSightController", "m_bIronSightAvailable"); }
    void SetIronSightAvailable(bool value) { SetSchemaValue(m_ptr, "C_IronSightController", "m_bIronSightAvailable", false, value); }
    float GetIronSightAmount() const { return GetSchemaValue<float>(m_ptr, "C_IronSightController", "m_flIronSightAmount"); }
    void SetIronSightAmount(float value) { SetSchemaValue(m_ptr, "C_IronSightController", "m_flIronSightAmount", false, value); }
    float GetIronSightAmountGained() const { return GetSchemaValue<float>(m_ptr, "C_IronSightController", "m_flIronSightAmountGained"); }
    void SetIronSightAmountGained(float value) { SetSchemaValue(m_ptr, "C_IronSightController", "m_flIronSightAmountGained", false, value); }
    float GetIronSightAmountBiased() const { return GetSchemaValue<float>(m_ptr, "C_IronSightController", "m_flIronSightAmountBiased"); }
    void SetIronSightAmountBiased(float value) { SetSchemaValue(m_ptr, "C_IronSightController", "m_flIronSightAmountBiased", false, value); }
    float GetIronSightAmount_Interpolated() const { return GetSchemaValue<float>(m_ptr, "C_IronSightController", "m_flIronSightAmount_Interpolated"); }
    void SetIronSightAmount_Interpolated(float value) { SetSchemaValue(m_ptr, "C_IronSightController", "m_flIronSightAmount_Interpolated", false, value); }
    float GetIronSightAmountGained_Interpolated() const { return GetSchemaValue<float>(m_ptr, "C_IronSightController", "m_flIronSightAmountGained_Interpolated"); }
    void SetIronSightAmountGained_Interpolated(float value) { SetSchemaValue(m_ptr, "C_IronSightController", "m_flIronSightAmountGained_Interpolated", false, value); }
    float GetIronSightAmountBiased_Interpolated() const { return GetSchemaValue<float>(m_ptr, "C_IronSightController", "m_flIronSightAmountBiased_Interpolated"); }
    void SetIronSightAmountBiased_Interpolated(float value) { SetSchemaValue(m_ptr, "C_IronSightController", "m_flIronSightAmountBiased_Interpolated", false, value); }
    float GetInterpolationLastUpdated() const { return GetSchemaValue<float>(m_ptr, "C_IronSightController", "m_flInterpolationLastUpdated"); }
    void SetInterpolationLastUpdated(float value) { SetSchemaValue(m_ptr, "C_IronSightController", "m_flInterpolationLastUpdated", false, value); }
    std::vector<QAngle> GetDeltaAverage() const { QAngle* outValue = GetSchemaValue<QAngle*>(m_ptr, "C_IronSightController", "m_angDeltaAverage"); std::vector<QAngle> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetDeltaAverage(std::vector<QAngle> value) { QAngle* outValue = GetSchemaValue<QAngle*>(m_ptr, "C_IronSightController", "m_angDeltaAverage"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "C_IronSightController", "m_angDeltaAverage", false, outValue); }
    QAngle GetViewLast() const { return GetSchemaValue<QAngle>(m_ptr, "C_IronSightController", "m_angViewLast"); }
    void SetViewLast(QAngle value) { SetSchemaValue(m_ptr, "C_IronSightController", "m_angViewLast", false, value); }
    Vector2D GetDotCoords() const { return GetSchemaValue<Vector2D>(m_ptr, "C_IronSightController", "m_vecDotCoords"); }
    void SetDotCoords(Vector2D value) { SetSchemaValue(m_ptr, "C_IronSightController", "m_vecDotCoords", false, value); }
    float GetDotBlur() const { return GetSchemaValue<float>(m_ptr, "C_IronSightController", "m_flDotBlur"); }
    void SetDotBlur(float value) { SetSchemaValue(m_ptr, "C_IronSightController", "m_flDotBlur", false, value); }
    float GetSpeedRatio() const { return GetSchemaValue<float>(m_ptr, "C_IronSightController", "m_flSpeedRatio"); }
    void SetSpeedRatio(float value) { SetSchemaValue(m_ptr, "C_IronSightController", "m_flSpeedRatio", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif