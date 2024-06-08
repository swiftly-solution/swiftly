class GFeBuildTaperedCapsuleRigid_t;

#ifndef _gcfebuildtaperedcapsulerigid_t_h
#define _gcfebuildtaperedcapsulerigid_t_h

#include "../../../scripting.h"




class GFeBuildTaperedCapsuleRigid_t
{
private:
    void *m_ptr;

public:
    GFeBuildTaperedCapsuleRigid_t() {}
    GFeBuildTaperedCapsuleRigid_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetPriority() const { return GetSchemaValue<int32_t>(m_ptr, "FeBuildTaperedCapsuleRigid_t", "m_nPriority"); }
    void SetPriority(int32_t value) { SetSchemaValue(m_ptr, "FeBuildTaperedCapsuleRigid_t", "m_nPriority", true, value); }
    uint32_t GetVertexMapHash() const { return GetSchemaValue<uint32_t>(m_ptr, "FeBuildTaperedCapsuleRigid_t", "m_nVertexMapHash"); }
    void SetVertexMapHash(uint32_t value) { SetSchemaValue(m_ptr, "FeBuildTaperedCapsuleRigid_t", "m_nVertexMapHash", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif