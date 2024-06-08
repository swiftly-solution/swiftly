class GC_INIT_VelocityFromCP;

#ifndef _gcc_init_velocityfromcp_h
#define _gcc_init_velocityfromcp_h

#include "../../../scripting.h"


#include "GCParticleTransformInput.h"

class GC_INIT_VelocityFromCP
{
private:
    void *m_ptr;

public:
    GC_INIT_VelocityFromCP() {}
    GC_INIT_VelocityFromCP(void *ptr) : m_ptr(ptr) {}

    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_VelocityFromCP", "m_transformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_VelocityFromCP", "m_transformInput", false, value); }
    float GetVelocityScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_VelocityFromCP", "m_flVelocityScale"); }
    void SetVelocityScale(float value) { SetSchemaValue(m_ptr, "C_INIT_VelocityFromCP", "m_flVelocityScale", false, value); }
    bool GetDirectionOnly() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_VelocityFromCP", "m_bDirectionOnly"); }
    void SetDirectionOnly(bool value) { SetSchemaValue(m_ptr, "C_INIT_VelocityFromCP", "m_bDirectionOnly", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif