class GC_OP_RenderTonemapController;

#ifndef _gcc_op_rendertonemapcontroller_h
#define _gcc_op_rendertonemapcontroller_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RenderTonemapController
{
private:
    void *m_ptr;

public:
    GC_OP_RenderTonemapController() {}
    GC_OP_RenderTonemapController(void *ptr) : m_ptr(ptr) {}

    float GetTonemapLevel() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTonemapController", "m_flTonemapLevel"); }
    void SetTonemapLevel(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTonemapController", "m_flTonemapLevel", false, value); }
    float GetTonemapWeight() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTonemapController", "m_flTonemapWeight"); }
    void SetTonemapWeight(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTonemapController", "m_flTonemapWeight", false, value); }
    GParticleAttributeIndex_t GetTonemapLevelField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderTonemapController", "m_nTonemapLevelField"); }
    void SetTonemapLevelField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderTonemapController", "m_nTonemapLevelField", false, value); }
    GParticleAttributeIndex_t GetTonemapWeightField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderTonemapController", "m_nTonemapWeightField"); }
    void SetTonemapWeightField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderTonemapController", "m_nTonemapWeightField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif