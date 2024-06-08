class GC_INIT_CreatePhyllotaxis;

#ifndef _gcc_init_createphyllotaxis_h
#define _gcc_init_createphyllotaxis_h

#include "../../../scripting.h"




class GC_INIT_CreatePhyllotaxis
{
private:
    void *m_ptr;

public:
    GC_INIT_CreatePhyllotaxis() {}
    GC_INIT_CreatePhyllotaxis(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_nControlPointNumber", false, value); }
    int32_t GetScaleCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_nScaleCP"); }
    void SetScaleCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_nScaleCP", false, value); }
    int32_t GetComponent() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_nComponent"); }
    void SetComponent(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_nComponent", false, value); }
    float GetRadCentCore() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fRadCentCore"); }
    void SetRadCentCore(float value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fRadCentCore", false, value); }
    float GetRadPerPoint() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fRadPerPoint"); }
    void SetRadPerPoint(float value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fRadPerPoint", false, value); }
    float GetRadPerPointTo() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fRadPerPointTo"); }
    void SetRadPerPointTo(float value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fRadPerPointTo", false, value); }
    float GetFpointAngle() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fpointAngle"); }
    void SetFpointAngle(float value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fpointAngle", false, value); }
    float GetFsizeOverall() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fsizeOverall"); }
    void SetFsizeOverall(float value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fsizeOverall", false, value); }
    float GetRadBias() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fRadBias"); }
    void SetRadBias(float value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fRadBias", false, value); }
    float GetMinRad() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fMinRad"); }
    void SetMinRad(float value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fMinRad", false, value); }
    float GetDistBias() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fDistBias"); }
    void SetDistBias(float value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_fDistBias", false, value); }
    bool GetUseLocalCoords() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_bUseLocalCoords"); }
    void SetUseLocalCoords(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_bUseLocalCoords", false, value); }
    bool GetUseWithContEmit() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_bUseWithContEmit"); }
    void SetUseWithContEmit(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_bUseWithContEmit", false, value); }
    bool GetUseOrigRadius() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreatePhyllotaxis", "m_bUseOrigRadius"); }
    void SetUseOrigRadius(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreatePhyllotaxis", "m_bUseOrigRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif