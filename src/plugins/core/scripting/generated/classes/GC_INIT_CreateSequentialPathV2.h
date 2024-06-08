class GC_INIT_CreateSequentialPathV2;

#ifndef _gcc_init_createsequentialpathv2_h
#define _gcc_init_createsequentialpathv2_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"
#include "GCParticleCollectionFloatInput.h"
#include "GCPathParameters.h"

class GC_INIT_CreateSequentialPathV2
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateSequentialPathV2() {}
    GC_INIT_CreateSequentialPathV2(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetMaxDistance() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_CreateSequentialPathV2", "m_fMaxDistance"); }
    void SetMaxDistance(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateSequentialPathV2", "m_fMaxDistance", false, value); }
    GCParticleCollectionFloatInput GetNumToAssign() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateSequentialPathV2", "m_flNumToAssign"); }
    void SetNumToAssign(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateSequentialPathV2", "m_flNumToAssign", false, value); }
    bool GetLoop() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateSequentialPathV2", "m_bLoop"); }
    void SetLoop(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateSequentialPathV2", "m_bLoop", false, value); }
    bool GetCPPairs() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateSequentialPathV2", "m_bCPPairs"); }
    void SetCPPairs(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateSequentialPathV2", "m_bCPPairs", false, value); }
    bool GetSaveOffset() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateSequentialPathV2", "m_bSaveOffset"); }
    void SetSaveOffset(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateSequentialPathV2", "m_bSaveOffset", false, value); }
    GCPathParameters GetPathParams() const { return GetSchemaValue<GCPathParameters>(m_ptr, "C_INIT_CreateSequentialPathV2", "m_PathParams"); }
    void SetPathParams(GCPathParameters value) { SetSchemaValue(m_ptr, "C_INIT_CreateSequentialPathV2", "m_PathParams", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif