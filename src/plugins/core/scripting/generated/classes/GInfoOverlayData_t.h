class GInfoOverlayData_t;

#ifndef _gcinfooverlaydata_t_h
#define _gcinfooverlaydata_t_h

#include "../../../scripting.h"




class GInfoOverlayData_t
{
private:
    void *m_ptr;

public:
    GInfoOverlayData_t() {}
    GInfoOverlayData_t(void *ptr) : m_ptr(ptr) {}

    matrix3x4_t GetTransform() const { return GetSchemaValue<matrix3x4_t>(m_ptr, "InfoOverlayData_t", "m_transform"); }
    void SetTransform(matrix3x4_t value) { SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_transform", true, value); }
    float GetWidth() const { return GetSchemaValue<float>(m_ptr, "InfoOverlayData_t", "m_flWidth"); }
    void SetWidth(float value) { SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_flWidth", true, value); }
    float GetHeight() const { return GetSchemaValue<float>(m_ptr, "InfoOverlayData_t", "m_flHeight"); }
    void SetHeight(float value) { SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_flHeight", true, value); }
    float GetDepth() const { return GetSchemaValue<float>(m_ptr, "InfoOverlayData_t", "m_flDepth"); }
    void SetDepth(float value) { SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_flDepth", true, value); }
    Vector2D GetUVStart() const { return GetSchemaValue<Vector2D>(m_ptr, "InfoOverlayData_t", "m_vUVStart"); }
    void SetUVStart(Vector2D value) { SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_vUVStart", true, value); }
    Vector2D GetUVEnd() const { return GetSchemaValue<Vector2D>(m_ptr, "InfoOverlayData_t", "m_vUVEnd"); }
    void SetUVEnd(Vector2D value) { SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_vUVEnd", true, value); }
    int32_t GetRenderOrder() const { return GetSchemaValue<int32_t>(m_ptr, "InfoOverlayData_t", "m_nRenderOrder"); }
    void SetRenderOrder(int32_t value) { SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_nRenderOrder", true, value); }
    Vector4D GetTintColor() const { return GetSchemaValue<Vector4D>(m_ptr, "InfoOverlayData_t", "m_vTintColor"); }
    void SetTintColor(Vector4D value) { SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_vTintColor", true, value); }
    int32_t GetSequenceOverride() const { return GetSchemaValue<int32_t>(m_ptr, "InfoOverlayData_t", "m_nSequenceOverride"); }
    void SetSequenceOverride(int32_t value) { SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_nSequenceOverride", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif