class GDynamicMeshDeformParams_t;

#ifndef _gcdynamicmeshdeformparams_t_h
#define _gcdynamicmeshdeformparams_t_h

#include "../../../scripting.h"




class GDynamicMeshDeformParams_t
{
private:
    void *m_ptr;

public:
    GDynamicMeshDeformParams_t() {}
    GDynamicMeshDeformParams_t(void *ptr) : m_ptr(ptr) {}

    float GetTensionCompressScale() const { return GetSchemaValue<float>(m_ptr, "DynamicMeshDeformParams_t", "m_flTensionCompressScale"); }
    void SetTensionCompressScale(float value) { SetSchemaValue(m_ptr, "DynamicMeshDeformParams_t", "m_flTensionCompressScale", true, value); }
    float GetTensionStretchScale() const { return GetSchemaValue<float>(m_ptr, "DynamicMeshDeformParams_t", "m_flTensionStretchScale"); }
    void SetTensionStretchScale(float value) { SetSchemaValue(m_ptr, "DynamicMeshDeformParams_t", "m_flTensionStretchScale", true, value); }
    bool GetRecomputeSmoothNormalsAfterAnimation() const { return GetSchemaValue<bool>(m_ptr, "DynamicMeshDeformParams_t", "m_bRecomputeSmoothNormalsAfterAnimation"); }
    void SetRecomputeSmoothNormalsAfterAnimation(bool value) { SetSchemaValue(m_ptr, "DynamicMeshDeformParams_t", "m_bRecomputeSmoothNormalsAfterAnimation", true, value); }
    bool GetComputeDynamicMeshTensionAfterAnimation() const { return GetSchemaValue<bool>(m_ptr, "DynamicMeshDeformParams_t", "m_bComputeDynamicMeshTensionAfterAnimation"); }
    void SetComputeDynamicMeshTensionAfterAnimation(bool value) { SetSchemaValue(m_ptr, "DynamicMeshDeformParams_t", "m_bComputeDynamicMeshTensionAfterAnimation", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif