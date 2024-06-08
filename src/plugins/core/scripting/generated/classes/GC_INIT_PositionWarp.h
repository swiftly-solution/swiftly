class GC_INIT_PositionWarp;

#ifndef _gcc_init_positionwarp_h
#define _gcc_init_positionwarp_h

#include "../../../scripting.h"




class GC_INIT_PositionWarp
{
private:
    void *m_ptr;

public:
    GC_INIT_PositionWarp() {}
    GC_INIT_PositionWarp(void *ptr) : m_ptr(ptr) {}

    int32_t GetScaleControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_PositionWarp", "m_nScaleControlPointNumber"); }
    void SetScaleControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarp", "m_nScaleControlPointNumber", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_PositionWarp", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarp", "m_nControlPointNumber", false, value); }
    int32_t GetRadiusComponent() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_PositionWarp", "m_nRadiusComponent"); }
    void SetRadiusComponent(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarp", "m_nRadiusComponent", false, value); }
    float GetWarpTime() const { return GetSchemaValue<float>(m_ptr, "C_INIT_PositionWarp", "m_flWarpTime"); }
    void SetWarpTime(float value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarp", "m_flWarpTime", false, value); }
    float GetWarpStartTime() const { return GetSchemaValue<float>(m_ptr, "C_INIT_PositionWarp", "m_flWarpStartTime"); }
    void SetWarpStartTime(float value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarp", "m_flWarpStartTime", false, value); }
    float GetPrevPosScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_PositionWarp", "m_flPrevPosScale"); }
    void SetPrevPosScale(float value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarp", "m_flPrevPosScale", false, value); }
    bool GetInvertWarp() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PositionWarp", "m_bInvertWarp"); }
    void SetInvertWarp(bool value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarp", "m_bInvertWarp", false, value); }
    bool GetUseCount() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PositionWarp", "m_bUseCount"); }
    void SetUseCount(bool value) { SetSchemaValue(m_ptr, "C_INIT_PositionWarp", "m_bUseCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif