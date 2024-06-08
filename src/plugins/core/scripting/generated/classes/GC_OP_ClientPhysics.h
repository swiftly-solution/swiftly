class GC_OP_ClientPhysics;

#ifndef _gcc_op_clientphysics_h
#define _gcc_op_clientphysics_h

#include "../../../scripting.h"

#include "../types/GParticleColorBlendType_t.h"


class GC_OP_ClientPhysics
{
private:
    void *m_ptr;

public:
    GC_OP_ClientPhysics() {}
    GC_OP_ClientPhysics(void *ptr) : m_ptr(ptr) {}

    CUtlString GetStrPhysicsType() const { return GetSchemaValue<CUtlString>(m_ptr, "C_OP_ClientPhysics", "m_strPhysicsType"); }
    void SetStrPhysicsType(CUtlString value) { SetSchemaValue(m_ptr, "C_OP_ClientPhysics", "m_strPhysicsType", false, value); }
    bool GetKillParticles() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ClientPhysics", "m_bKillParticles"); }
    void SetKillParticles(bool value) { SetSchemaValue(m_ptr, "C_OP_ClientPhysics", "m_bKillParticles", false, value); }
    bool GetDeleteSim() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ClientPhysics", "m_bDeleteSim"); }
    void SetDeleteSim(bool value) { SetSchemaValue(m_ptr, "C_OP_ClientPhysics", "m_bDeleteSim", false, value); }
    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ClientPhysics", "m_nControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ClientPhysics", "m_nControlPoint", false, value); }
    ParticleColorBlendType_t GetColorBlendType() const { return GetSchemaValue<ParticleColorBlendType_t>(m_ptr, "C_OP_ClientPhysics", "m_nColorBlendType"); }
    void SetColorBlendType(ParticleColorBlendType_t value) { SetSchemaValue(m_ptr, "C_OP_ClientPhysics", "m_nColorBlendType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif