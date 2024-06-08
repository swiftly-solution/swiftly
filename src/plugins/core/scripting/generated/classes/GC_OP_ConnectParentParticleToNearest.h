class GC_OP_ConnectParentParticleToNearest;

#ifndef _gcc_op_connectparentparticletonearest_h
#define _gcc_op_connectparentparticletonearest_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_ConnectParentParticleToNearest
{
private:
    void *m_ptr;

public:
    GC_OP_ConnectParentParticleToNearest() {}
    GC_OP_ConnectParentParticleToNearest(void *ptr) : m_ptr(ptr) {}

    int32_t GetFirstControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ConnectParentParticleToNearest", "m_nFirstControlPoint"); }
    void SetFirstControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ConnectParentParticleToNearest", "m_nFirstControlPoint", false, value); }
    int32_t GetSecondControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ConnectParentParticleToNearest", "m_nSecondControlPoint"); }
    void SetSecondControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ConnectParentParticleToNearest", "m_nSecondControlPoint", false, value); }
    bool GetUseRadius() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ConnectParentParticleToNearest", "m_bUseRadius"); }
    void SetUseRadius(bool value) { SetSchemaValue(m_ptr, "C_OP_ConnectParentParticleToNearest", "m_bUseRadius", false, value); }
    GCParticleCollectionFloatInput GetRadiusScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_ConnectParentParticleToNearest", "m_flRadiusScale"); }
    void SetRadiusScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ConnectParentParticleToNearest", "m_flRadiusScale", false, value); }
    GCParticleCollectionFloatInput GetParentRadiusScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_ConnectParentParticleToNearest", "m_flParentRadiusScale"); }
    void SetParentRadiusScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ConnectParentParticleToNearest", "m_flParentRadiusScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif