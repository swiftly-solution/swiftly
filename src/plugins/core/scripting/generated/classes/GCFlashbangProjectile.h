class GCFlashbangProjectile;

#ifndef _gccflashbangprojectile_h
#define _gccflashbangprojectile_h

#include "../../../scripting.h"




class GCFlashbangProjectile
{
private:
    void *m_ptr;

public:
    GCFlashbangProjectile() {}
    GCFlashbangProjectile(void *ptr) : m_ptr(ptr) {}

    float GetTimeToDetonate() const { return GetSchemaValue<float>(m_ptr, "CFlashbangProjectile", "m_flTimeToDetonate"); }
    void SetTimeToDetonate(float value) { SetSchemaValue(m_ptr, "CFlashbangProjectile", "m_flTimeToDetonate", false, value); }
    uint8_t GetNumOpponentsHit() const { return GetSchemaValue<uint8_t>(m_ptr, "CFlashbangProjectile", "m_numOpponentsHit"); }
    void SetNumOpponentsHit(uint8_t value) { SetSchemaValue(m_ptr, "CFlashbangProjectile", "m_numOpponentsHit", false, value); }
    uint8_t GetNumTeammatesHit() const { return GetSchemaValue<uint8_t>(m_ptr, "CFlashbangProjectile", "m_numTeammatesHit"); }
    void SetNumTeammatesHit(uint8_t value) { SetSchemaValue(m_ptr, "CFlashbangProjectile", "m_numTeammatesHit", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif