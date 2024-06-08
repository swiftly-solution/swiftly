class GC_OP_IntraParticleForce;

#ifndef _gcc_op_intraparticleforce_h
#define _gcc_op_intraparticleforce_h

#include "../../../scripting.h"




class GC_OP_IntraParticleForce
{
private:
    void *m_ptr;

public:
    GC_OP_IntraParticleForce() {}
    GC_OP_IntraParticleForce(void *ptr) : m_ptr(ptr) {}

    float GetAttractionMinDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_IntraParticleForce", "m_flAttractionMinDistance"); }
    void SetAttractionMinDistance(float value) { SetSchemaValue(m_ptr, "C_OP_IntraParticleForce", "m_flAttractionMinDistance", false, value); }
    float GetAttractionMaxDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_IntraParticleForce", "m_flAttractionMaxDistance"); }
    void SetAttractionMaxDistance(float value) { SetSchemaValue(m_ptr, "C_OP_IntraParticleForce", "m_flAttractionMaxDistance", false, value); }
    float GetAttractionMaxStrength() const { return GetSchemaValue<float>(m_ptr, "C_OP_IntraParticleForce", "m_flAttractionMaxStrength"); }
    void SetAttractionMaxStrength(float value) { SetSchemaValue(m_ptr, "C_OP_IntraParticleForce", "m_flAttractionMaxStrength", false, value); }
    float GetRepulsionMinDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_IntraParticleForce", "m_flRepulsionMinDistance"); }
    void SetRepulsionMinDistance(float value) { SetSchemaValue(m_ptr, "C_OP_IntraParticleForce", "m_flRepulsionMinDistance", false, value); }
    float GetRepulsionMaxDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_IntraParticleForce", "m_flRepulsionMaxDistance"); }
    void SetRepulsionMaxDistance(float value) { SetSchemaValue(m_ptr, "C_OP_IntraParticleForce", "m_flRepulsionMaxDistance", false, value); }
    float GetRepulsionMaxStrength() const { return GetSchemaValue<float>(m_ptr, "C_OP_IntraParticleForce", "m_flRepulsionMaxStrength"); }
    void SetRepulsionMaxStrength(float value) { SetSchemaValue(m_ptr, "C_OP_IntraParticleForce", "m_flRepulsionMaxStrength", false, value); }
    bool GetUseAABB() const { return GetSchemaValue<bool>(m_ptr, "C_OP_IntraParticleForce", "m_bUseAABB"); }
    void SetUseAABB(bool value) { SetSchemaValue(m_ptr, "C_OP_IntraParticleForce", "m_bUseAABB", false, value); }
    bool GetThreadIt() const { return GetSchemaValue<bool>(m_ptr, "C_OP_IntraParticleForce", "m_bThreadIt"); }
    void SetThreadIt(bool value) { SetSchemaValue(m_ptr, "C_OP_IntraParticleForce", "m_bThreadIt", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif