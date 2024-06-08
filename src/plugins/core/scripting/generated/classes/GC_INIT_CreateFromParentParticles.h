class GC_INIT_CreateFromParentParticles;

#ifndef _gcc_init_createfromparentparticles_h
#define _gcc_init_createfromparentparticles_h

#include "../../../scripting.h"




class GC_INIT_CreateFromParentParticles
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateFromParentParticles() {}
    GC_INIT_CreateFromParentParticles(void *ptr) : m_ptr(ptr) {}

    float GetVelocityScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreateFromParentParticles", "m_flVelocityScale"); }
    void SetVelocityScale(float value) { SetSchemaValue(m_ptr, "C_INIT_CreateFromParentParticles", "m_flVelocityScale", false, value); }
    float GetIncrement() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreateFromParentParticles", "m_flIncrement"); }
    void SetIncrement(float value) { SetSchemaValue(m_ptr, "C_INIT_CreateFromParentParticles", "m_flIncrement", false, value); }
    bool GetRandomDistribution() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateFromParentParticles", "m_bRandomDistribution"); }
    void SetRandomDistribution(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateFromParentParticles", "m_bRandomDistribution", false, value); }
    int32_t GetRandomSeed() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateFromParentParticles", "m_nRandomSeed"); }
    void SetRandomSeed(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateFromParentParticles", "m_nRandomSeed", false, value); }
    bool GetSubFrame() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateFromParentParticles", "m_bSubFrame"); }
    void SetSubFrame(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateFromParentParticles", "m_bSubFrame", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif