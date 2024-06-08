class GC_OP_ControlpointLight;

#ifndef _gcc_op_controlpointlight_h
#define _gcc_op_controlpointlight_h

#include "../../../scripting.h"




class GC_OP_ControlpointLight
{
private:
    void *m_ptr;

public:
    GC_OP_ControlpointLight() {}
    GC_OP_ControlpointLight(void *ptr) : m_ptr(ptr) {}

    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_ControlpointLight", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_flScale", false, value); }
    int32_t GetControlPoint1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ControlpointLight", "m_nControlPoint1"); }
    void SetControlPoint1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_nControlPoint1", false, value); }
    int32_t GetControlPoint2() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ControlpointLight", "m_nControlPoint2"); }
    void SetControlPoint2(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_nControlPoint2", false, value); }
    int32_t GetControlPoint3() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ControlpointLight", "m_nControlPoint3"); }
    void SetControlPoint3(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_nControlPoint3", false, value); }
    int32_t GetControlPoint4() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ControlpointLight", "m_nControlPoint4"); }
    void SetControlPoint4(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_nControlPoint4", false, value); }
    Vector GetCPOffset1() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_ControlpointLight", "m_vecCPOffset1"); }
    void SetCPOffset1(Vector value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_vecCPOffset1", false, value); }
    Vector GetCPOffset2() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_ControlpointLight", "m_vecCPOffset2"); }
    void SetCPOffset2(Vector value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_vecCPOffset2", false, value); }
    Vector GetCPOffset3() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_ControlpointLight", "m_vecCPOffset3"); }
    void SetCPOffset3(Vector value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_vecCPOffset3", false, value); }
    Vector GetCPOffset4() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_ControlpointLight", "m_vecCPOffset4"); }
    void SetCPOffset4(Vector value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_vecCPOffset4", false, value); }
    float GetLightFiftyDist1() const { return GetSchemaValue<float>(m_ptr, "C_OP_ControlpointLight", "m_LightFiftyDist1"); }
    void SetLightFiftyDist1(float value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_LightFiftyDist1", false, value); }
    float GetLightZeroDist1() const { return GetSchemaValue<float>(m_ptr, "C_OP_ControlpointLight", "m_LightZeroDist1"); }
    void SetLightZeroDist1(float value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_LightZeroDist1", false, value); }
    float GetLightFiftyDist2() const { return GetSchemaValue<float>(m_ptr, "C_OP_ControlpointLight", "m_LightFiftyDist2"); }
    void SetLightFiftyDist2(float value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_LightFiftyDist2", false, value); }
    float GetLightZeroDist2() const { return GetSchemaValue<float>(m_ptr, "C_OP_ControlpointLight", "m_LightZeroDist2"); }
    void SetLightZeroDist2(float value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_LightZeroDist2", false, value); }
    float GetLightFiftyDist3() const { return GetSchemaValue<float>(m_ptr, "C_OP_ControlpointLight", "m_LightFiftyDist3"); }
    void SetLightFiftyDist3(float value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_LightFiftyDist3", false, value); }
    float GetLightZeroDist3() const { return GetSchemaValue<float>(m_ptr, "C_OP_ControlpointLight", "m_LightZeroDist3"); }
    void SetLightZeroDist3(float value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_LightZeroDist3", false, value); }
    float GetLightFiftyDist4() const { return GetSchemaValue<float>(m_ptr, "C_OP_ControlpointLight", "m_LightFiftyDist4"); }
    void SetLightFiftyDist4(float value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_LightFiftyDist4", false, value); }
    float GetLightZeroDist4() const { return GetSchemaValue<float>(m_ptr, "C_OP_ControlpointLight", "m_LightZeroDist4"); }
    void SetLightZeroDist4(float value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_LightZeroDist4", false, value); }
    Color GetLightColor1() const { return GetSchemaValue<Color>(m_ptr, "C_OP_ControlpointLight", "m_LightColor1"); }
    void SetLightColor1(Color value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_LightColor1", false, value); }
    Color GetLightColor2() const { return GetSchemaValue<Color>(m_ptr, "C_OP_ControlpointLight", "m_LightColor2"); }
    void SetLightColor2(Color value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_LightColor2", false, value); }
    Color GetLightColor3() const { return GetSchemaValue<Color>(m_ptr, "C_OP_ControlpointLight", "m_LightColor3"); }
    void SetLightColor3(Color value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_LightColor3", false, value); }
    Color GetLightColor4() const { return GetSchemaValue<Color>(m_ptr, "C_OP_ControlpointLight", "m_LightColor4"); }
    void SetLightColor4(Color value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_LightColor4", false, value); }
    bool GetLightType1() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ControlpointLight", "m_bLightType1"); }
    void SetLightType1(bool value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_bLightType1", false, value); }
    bool GetLightType2() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ControlpointLight", "m_bLightType2"); }
    void SetLightType2(bool value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_bLightType2", false, value); }
    bool GetLightType3() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ControlpointLight", "m_bLightType3"); }
    void SetLightType3(bool value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_bLightType3", false, value); }
    bool GetLightType4() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ControlpointLight", "m_bLightType4"); }
    void SetLightType4(bool value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_bLightType4", false, value); }
    bool GetLightDynamic1() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ControlpointLight", "m_bLightDynamic1"); }
    void SetLightDynamic1(bool value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_bLightDynamic1", false, value); }
    bool GetLightDynamic2() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ControlpointLight", "m_bLightDynamic2"); }
    void SetLightDynamic2(bool value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_bLightDynamic2", false, value); }
    bool GetLightDynamic3() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ControlpointLight", "m_bLightDynamic3"); }
    void SetLightDynamic3(bool value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_bLightDynamic3", false, value); }
    bool GetLightDynamic4() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ControlpointLight", "m_bLightDynamic4"); }
    void SetLightDynamic4(bool value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_bLightDynamic4", false, value); }
    bool GetUseNormal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ControlpointLight", "m_bUseNormal"); }
    void SetUseNormal(bool value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_bUseNormal", false, value); }
    bool GetUseHLambert() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ControlpointLight", "m_bUseHLambert"); }
    void SetUseHLambert(bool value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_bUseHLambert", false, value); }
    bool GetClampLowerRange() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ControlpointLight", "m_bClampLowerRange"); }
    void SetClampLowerRange(bool value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_bClampLowerRange", false, value); }
    bool GetClampUpperRange() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ControlpointLight", "m_bClampUpperRange"); }
    void SetClampUpperRange(bool value) { SetSchemaValue(m_ptr, "C_OP_ControlpointLight", "m_bClampUpperRange", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif