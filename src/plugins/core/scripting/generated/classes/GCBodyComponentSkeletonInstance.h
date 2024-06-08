class GCBodyComponentSkeletonInstance;

#ifndef _gccbodycomponentskeletoninstance_h
#define _gccbodycomponentskeletoninstance_h

#include "../../../scripting.h"


#include "GCSkeletonInstance.h"

class GCBodyComponentSkeletonInstance
{
private:
    void *m_ptr;

public:
    GCBodyComponentSkeletonInstance() {}
    GCBodyComponentSkeletonInstance(void *ptr) : m_ptr(ptr) {}

    GCSkeletonInstance GetSkeletonInstance() const { return GetSchemaValue<GCSkeletonInstance>(m_ptr, "CBodyComponentSkeletonInstance", "m_skeletonInstance"); }
    void SetSkeletonInstance(GCSkeletonInstance value) { SetSchemaValue(m_ptr, "CBodyComponentSkeletonInstance", "m_skeletonInstance", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif