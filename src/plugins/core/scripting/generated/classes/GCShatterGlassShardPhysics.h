class GCShatterGlassShardPhysics;

#ifndef _gccshatterglassshardphysics_h
#define _gccshatterglassshardphysics_h

#include "../../../scripting.h"


#include "Gshard_model_desc_t.h"

class GCShatterGlassShardPhysics
{
private:
    void *m_ptr;

public:
    GCShatterGlassShardPhysics() {}
    GCShatterGlassShardPhysics(void *ptr) : m_ptr(ptr) {}

    bool GetDebris() const { return GetSchemaValue<bool>(m_ptr, "CShatterGlassShardPhysics", "m_bDebris"); }
    void SetDebris(bool value) { SetSchemaValue(m_ptr, "CShatterGlassShardPhysics", "m_bDebris", false, value); }
    uint32_t GetParentShard() const { return GetSchemaValue<uint32_t>(m_ptr, "CShatterGlassShardPhysics", "m_hParentShard"); }
    void SetParentShard(uint32_t value) { SetSchemaValue(m_ptr, "CShatterGlassShardPhysics", "m_hParentShard", false, value); }
    Gshard_model_desc_t GetShardDesc() const { return GetSchemaValue<Gshard_model_desc_t>(m_ptr, "CShatterGlassShardPhysics", "m_ShardDesc"); }
    void SetShardDesc(Gshard_model_desc_t value) { SetSchemaValue(m_ptr, "CShatterGlassShardPhysics", "m_ShardDesc", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif