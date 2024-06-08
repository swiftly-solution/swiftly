class GCBaseProp;

#ifndef _gccbaseprop_h
#define _gccbaseprop_h

#include "../../../scripting.h"




class GCBaseProp
{
private:
    void *m_ptr;

public:
    GCBaseProp() {}
    GCBaseProp(void *ptr) : m_ptr(ptr) {}

    bool GetModelOverrodeBlockLOS() const { return GetSchemaValue<bool>(m_ptr, "CBaseProp", "m_bModelOverrodeBlockLOS"); }
    void SetModelOverrodeBlockLOS(bool value) { SetSchemaValue(m_ptr, "CBaseProp", "m_bModelOverrodeBlockLOS", false, value); }
    int32_t GetShapeType() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseProp", "m_iShapeType"); }
    void SetShapeType(int32_t value) { SetSchemaValue(m_ptr, "CBaseProp", "m_iShapeType", false, value); }
    bool GetConformToCollisionBounds() const { return GetSchemaValue<bool>(m_ptr, "CBaseProp", "m_bConformToCollisionBounds"); }
    void SetConformToCollisionBounds(bool value) { SetSchemaValue(m_ptr, "CBaseProp", "m_bConformToCollisionBounds", false, value); }
    matrix3x4_t GetMPreferredCatchTransform() const { return GetSchemaValue<matrix3x4_t>(m_ptr, "CBaseProp", "m_mPreferredCatchTransform"); }
    void SetMPreferredCatchTransform(matrix3x4_t value) { SetSchemaValue(m_ptr, "CBaseProp", "m_mPreferredCatchTransform", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif