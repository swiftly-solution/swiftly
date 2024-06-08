class GCSolveIKTargetHandle_t;

#ifndef _gccsolveiktargethandle_t_h
#define _gccsolveiktargethandle_t_h

#include "../../../scripting.h"


#include "GCAnimParamHandle.h"

class GCSolveIKTargetHandle_t
{
private:
    void *m_ptr;

public:
    GCSolveIKTargetHandle_t() {}
    GCSolveIKTargetHandle_t(void *ptr) : m_ptr(ptr) {}

    GCAnimParamHandle GetPositionHandle() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CSolveIKTargetHandle_t", "m_positionHandle"); }
    void SetPositionHandle(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CSolveIKTargetHandle_t", "m_positionHandle", true, value); }
    GCAnimParamHandle GetOrientationHandle() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CSolveIKTargetHandle_t", "m_orientationHandle"); }
    void SetOrientationHandle(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CSolveIKTargetHandle_t", "m_orientationHandle", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif