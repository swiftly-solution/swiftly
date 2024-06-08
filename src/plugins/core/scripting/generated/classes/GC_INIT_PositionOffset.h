class GC_INIT_PositionOffset;

#ifndef _gcc_init_positionoffset_h
#define _gcc_init_positionoffset_h

#include "../../../scripting.h"


#include "GCPerParticleVecInput.h"
#include "GCParticleTransformInput.h"
#include "GCRandomNumberGeneratorParameters.h"

class GC_INIT_PositionOffset
{
private:
    void *m_ptr;

public:
    GC_INIT_PositionOffset() {}
    GC_INIT_PositionOffset(void *ptr) : m_ptr(ptr) {}

    GCPerParticleVecInput GetOffsetMin() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_PositionOffset", "m_OffsetMin"); }
    void SetOffsetMin(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_PositionOffset", "m_OffsetMin", false, value); }
    GCPerParticleVecInput GetOffsetMax() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_PositionOffset", "m_OffsetMax"); }
    void SetOffsetMax(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_PositionOffset", "m_OffsetMax", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_PositionOffset", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_PositionOffset", "m_TransformInput", false, value); }
    bool GetLocalCoords() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PositionOffset", "m_bLocalCoords"); }
    void SetLocalCoords(bool value) { SetSchemaValue(m_ptr, "C_INIT_PositionOffset", "m_bLocalCoords", false, value); }
    bool GetProportional() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PositionOffset", "m_bProportional"); }
    void SetProportional(bool value) { SetSchemaValue(m_ptr, "C_INIT_PositionOffset", "m_bProportional", false, value); }
    GCRandomNumberGeneratorParameters GetRandomnessParameters() const { return GetSchemaValue<GCRandomNumberGeneratorParameters>(m_ptr, "C_INIT_PositionOffset", "m_randomnessParameters"); }
    void SetRandomnessParameters(GCRandomNumberGeneratorParameters value) { SetSchemaValue(m_ptr, "C_INIT_PositionOffset", "m_randomnessParameters", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif