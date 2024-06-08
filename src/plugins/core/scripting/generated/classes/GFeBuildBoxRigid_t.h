class GFeBuildBoxRigid_t;

#ifndef _gcfebuildboxrigid_t_h
#define _gcfebuildboxrigid_t_h

#include "../../../scripting.h"




class GFeBuildBoxRigid_t
{
private:
    void *m_ptr;

public:
    GFeBuildBoxRigid_t() {}
    GFeBuildBoxRigid_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetPriority() const { return GetSchemaValue<int32_t>(m_ptr, "FeBuildBoxRigid_t", "m_nPriority"); }
    void SetPriority(int32_t value) { SetSchemaValue(m_ptr, "FeBuildBoxRigid_t", "m_nPriority", true, value); }
    uint32_t GetVertexMapHash() const { return GetSchemaValue<uint32_t>(m_ptr, "FeBuildBoxRigid_t", "m_nVertexMapHash"); }
    void SetVertexMapHash(uint32_t value) { SetSchemaValue(m_ptr, "FeBuildBoxRigid_t", "m_nVertexMapHash", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif