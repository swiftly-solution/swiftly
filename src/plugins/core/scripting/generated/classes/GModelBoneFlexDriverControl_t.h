class GModelBoneFlexDriverControl_t;

#ifndef _gcmodelboneflexdrivercontrol_t_h
#define _gcmodelboneflexdrivercontrol_t_h

#include "../../../scripting.h"

#include "../types/GModelBoneFlexComponent_t.h"


class GModelBoneFlexDriverControl_t
{
private:
    void *m_ptr;

public:
    GModelBoneFlexDriverControl_t() {}
    GModelBoneFlexDriverControl_t(void *ptr) : m_ptr(ptr) {}

    ModelBoneFlexComponent_t GetBoneComponent() const { return GetSchemaValue<ModelBoneFlexComponent_t>(m_ptr, "ModelBoneFlexDriverControl_t", "m_nBoneComponent"); }
    void SetBoneComponent(ModelBoneFlexComponent_t value) { SetSchemaValue(m_ptr, "ModelBoneFlexDriverControl_t", "m_nBoneComponent", true, value); }
    CUtlString GetFlexController() const { return GetSchemaValue<CUtlString>(m_ptr, "ModelBoneFlexDriverControl_t", "m_flexController"); }
    void SetFlexController(CUtlString value) { SetSchemaValue(m_ptr, "ModelBoneFlexDriverControl_t", "m_flexController", true, value); }
    uint32_t GetFlexControllerToken() const { return GetSchemaValue<uint32_t>(m_ptr, "ModelBoneFlexDriverControl_t", "m_flexControllerToken"); }
    void SetFlexControllerToken(uint32_t value) { SetSchemaValue(m_ptr, "ModelBoneFlexDriverControl_t", "m_flexControllerToken", true, value); }
    float GetMin() const { return GetSchemaValue<float>(m_ptr, "ModelBoneFlexDriverControl_t", "m_flMin"); }
    void SetMin(float value) { SetSchemaValue(m_ptr, "ModelBoneFlexDriverControl_t", "m_flMin", true, value); }
    float GetMax() const { return GetSchemaValue<float>(m_ptr, "ModelBoneFlexDriverControl_t", "m_flMax"); }
    void SetMax(float value) { SetSchemaValue(m_ptr, "ModelBoneFlexDriverControl_t", "m_flMax", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif