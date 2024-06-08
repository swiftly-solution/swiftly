class GC_INIT_GlobalScale;

#ifndef _gcc_init_globalscale_h
#define _gcc_init_globalscale_h

#include "../../../scripting.h"




class GC_INIT_GlobalScale
{
private:
    void *m_ptr;

public:
    GC_INIT_GlobalScale() {}
    GC_INIT_GlobalScale(void *ptr) : m_ptr(ptr) {}

    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_GlobalScale", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_INIT_GlobalScale", "m_flScale", false, value); }
    int32_t GetScaleControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_GlobalScale", "m_nScaleControlPointNumber"); }
    void SetScaleControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_GlobalScale", "m_nScaleControlPointNumber", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_GlobalScale", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_GlobalScale", "m_nControlPointNumber", false, value); }
    bool GetScaleRadius() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_GlobalScale", "m_bScaleRadius"); }
    void SetScaleRadius(bool value) { SetSchemaValue(m_ptr, "C_INIT_GlobalScale", "m_bScaleRadius", false, value); }
    bool GetScalePosition() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_GlobalScale", "m_bScalePosition"); }
    void SetScalePosition(bool value) { SetSchemaValue(m_ptr, "C_INIT_GlobalScale", "m_bScalePosition", false, value); }
    bool GetScaleVelocity() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_GlobalScale", "m_bScaleVelocity"); }
    void SetScaleVelocity(bool value) { SetSchemaValue(m_ptr, "C_INIT_GlobalScale", "m_bScaleVelocity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif