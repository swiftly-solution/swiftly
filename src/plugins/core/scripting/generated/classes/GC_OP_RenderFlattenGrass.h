class GC_OP_RenderFlattenGrass;

#ifndef _gcc_op_renderflattengrass_h
#define _gcc_op_renderflattengrass_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RenderFlattenGrass
{
private:
    void *m_ptr;

public:
    GC_OP_RenderFlattenGrass() {}
    GC_OP_RenderFlattenGrass(void *ptr) : m_ptr(ptr) {}

    float GetFlattenStrength() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderFlattenGrass", "m_flFlattenStrength"); }
    void SetFlattenStrength(float value) { SetSchemaValue(m_ptr, "C_OP_RenderFlattenGrass", "m_flFlattenStrength", false, value); }
    GParticleAttributeIndex_t GetStrengthFieldOverride() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderFlattenGrass", "m_nStrengthFieldOverride"); }
    void SetStrengthFieldOverride(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderFlattenGrass", "m_nStrengthFieldOverride", false, value); }
    float GetRadiusScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderFlattenGrass", "m_flRadiusScale"); }
    void SetRadiusScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderFlattenGrass", "m_flRadiusScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif