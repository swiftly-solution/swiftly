class GCSkeletonAnimationController;

#ifndef _gccskeletonanimationcontroller_h
#define _gccskeletonanimationcontroller_h

#include "../../../scripting.h"


#include "GCSkeletonInstance.h"

class GCSkeletonAnimationController
{
private:
    void *m_ptr;

public:
    GCSkeletonAnimationController() {}
    GCSkeletonAnimationController(void *ptr) : m_ptr(ptr) {}

    GCSkeletonInstance* GetSkeletonInstance() const { return GetSchemaValue<GCSkeletonInstance*>(m_ptr, "CSkeletonAnimationController", "m_pSkeletonInstance"); }
    void SetSkeletonInstance(GCSkeletonInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'SkeletonInstance' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif