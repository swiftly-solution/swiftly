class GCSkeletonInstance;

#ifndef _gccskeletoninstance_h
#define _gccskeletoninstance_h

#include "../../../scripting.h"


#include "GCModelState.h"

class GCSkeletonInstance
{
private:
    void *m_ptr;

public:
    GCSkeletonInstance() {}
    GCSkeletonInstance(void *ptr) : m_ptr(ptr) {}

    GCModelState GetModelState() const { return GetSchemaValue<GCModelState>(m_ptr, "CSkeletonInstance", "m_modelState"); }
    void SetModelState(GCModelState value) { SetSchemaValue(m_ptr, "CSkeletonInstance", "m_modelState", false, value); }
    bool GetIsAnimationEnabled() const { return GetSchemaValue<bool>(m_ptr, "CSkeletonInstance", "m_bIsAnimationEnabled"); }
    void SetIsAnimationEnabled(bool value) { SetSchemaValue(m_ptr, "CSkeletonInstance", "m_bIsAnimationEnabled", false, value); }
    bool GetUseParentRenderBounds() const { return GetSchemaValue<bool>(m_ptr, "CSkeletonInstance", "m_bUseParentRenderBounds"); }
    void SetUseParentRenderBounds(bool value) { SetSchemaValue(m_ptr, "CSkeletonInstance", "m_bUseParentRenderBounds", false, value); }
    bool GetDisableSolidCollisionsForHierarchy() const { return GetSchemaValue<bool>(m_ptr, "CSkeletonInstance", "m_bDisableSolidCollisionsForHierarchy"); }
    void SetDisableSolidCollisionsForHierarchy(bool value) { SetSchemaValue(m_ptr, "CSkeletonInstance", "m_bDisableSolidCollisionsForHierarchy", false, value); }
    CUtlStringToken GetMaterialGroup() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "CSkeletonInstance", "m_materialGroup"); }
    void SetMaterialGroup(CUtlStringToken value) { SetSchemaValue(m_ptr, "CSkeletonInstance", "m_materialGroup", false, value); }
    uint8_t GetHitboxSet() const { return GetSchemaValue<uint8_t>(m_ptr, "CSkeletonInstance", "m_nHitboxSet"); }
    void SetHitboxSet(uint8_t value) { SetSchemaValue(m_ptr, "CSkeletonInstance", "m_nHitboxSet", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif