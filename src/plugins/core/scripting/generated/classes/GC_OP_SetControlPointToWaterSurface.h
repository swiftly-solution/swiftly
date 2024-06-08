class GC_OP_SetControlPointToWaterSurface;

#ifndef _gcc_op_setcontrolpointtowatersurface_h
#define _gcc_op_setcontrolpointtowatersurface_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_SetControlPointToWaterSurface
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointToWaterSurface() {}
    GC_OP_SetControlPointToWaterSurface(void *ptr) : m_ptr(ptr) {}

    int32_t GetSourceCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_nSourceCP"); }
    void SetSourceCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_nSourceCP", false, value); }
    int32_t GetDestCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_nDestCP"); }
    void SetDestCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_nDestCP", false, value); }
    int32_t GetFlowCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_nFlowCP"); }
    void SetFlowCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_nFlowCP", false, value); }
    int32_t GetActiveCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_nActiveCP"); }
    void SetActiveCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_nActiveCP", false, value); }
    int32_t GetActiveCPField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_nActiveCPField"); }
    void SetActiveCPField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_nActiveCPField", false, value); }
    GCParticleCollectionFloatInput GetRetestRate() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_flRetestRate"); }
    void SetRetestRate(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_flRetestRate", false, value); }
    bool GetAdaptiveThreshold() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_bAdaptiveThreshold"); }
    void SetAdaptiveThreshold(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToWaterSurface", "m_bAdaptiveThreshold", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif