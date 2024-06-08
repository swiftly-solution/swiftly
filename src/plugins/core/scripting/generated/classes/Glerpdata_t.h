class Glerpdata_t;

#ifndef _gclerpdata_t_h
#define _gclerpdata_t_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "GParticleIndex_t.h"

class Glerpdata_t
{
private:
    void *m_ptr;

public:
    Glerpdata_t() {}
    Glerpdata_t(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetEnt() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "lerpdata_t", "m_hEnt"); }
    void SetEnt(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Ent' is not possible.\n"); }
    MoveType_t GetMoveType() const { return GetSchemaValue<MoveType_t>(m_ptr, "lerpdata_t", "m_MoveType"); }
    void SetMoveType(MoveType_t value) { SetSchemaValue(m_ptr, "lerpdata_t", "m_MoveType", true, value); }
    Vector GetStartOrigin() const { return GetSchemaValue<Vector>(m_ptr, "lerpdata_t", "m_vecStartOrigin"); }
    void SetStartOrigin(Vector value) { SetSchemaValue(m_ptr, "lerpdata_t", "m_vecStartOrigin", true, value); }
    Quaternion GetStartRot() const { return GetSchemaValue<Quaternion>(m_ptr, "lerpdata_t", "m_qStartRot"); }
    void SetStartRot(Quaternion value) { SetSchemaValue(m_ptr, "lerpdata_t", "m_qStartRot", true, value); }
    GParticleIndex_t GetFXIndex() const { return GetSchemaValue<GParticleIndex_t>(m_ptr, "lerpdata_t", "m_nFXIndex"); }
    void SetFXIndex(GParticleIndex_t value) { SetSchemaValue(m_ptr, "lerpdata_t", "m_nFXIndex", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif