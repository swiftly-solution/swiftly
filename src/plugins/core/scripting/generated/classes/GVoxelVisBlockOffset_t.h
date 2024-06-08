class GVoxelVisBlockOffset_t;

#ifndef _gcvoxelvisblockoffset_t_h
#define _gcvoxelvisblockoffset_t_h

#include "../../../scripting.h"




class GVoxelVisBlockOffset_t
{
private:
    void *m_ptr;

public:
    GVoxelVisBlockOffset_t() {}
    GVoxelVisBlockOffset_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetOffset() const { return GetSchemaValue<uint32_t>(m_ptr, "VoxelVisBlockOffset_t", "m_nOffset"); }
    void SetOffset(uint32_t value) { SetSchemaValue(m_ptr, "VoxelVisBlockOffset_t", "m_nOffset", true, value); }
    uint32_t GetElementCount() const { return GetSchemaValue<uint32_t>(m_ptr, "VoxelVisBlockOffset_t", "m_nElementCount"); }
    void SetElementCount(uint32_t value) { SetSchemaValue(m_ptr, "VoxelVisBlockOffset_t", "m_nElementCount", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif