class GCBreakableStageHelper;

#ifndef _gccbreakablestagehelper_h
#define _gccbreakablestagehelper_h

#include "../../../scripting.h"




class GCBreakableStageHelper
{
private:
    void *m_ptr;

public:
    GCBreakableStageHelper() {}
    GCBreakableStageHelper(void *ptr) : m_ptr(ptr) {}

    int32_t GetCurrentStage() const { return GetSchemaValue<int32_t>(m_ptr, "CBreakableStageHelper", "m_nCurrentStage"); }
    void SetCurrentStage(int32_t value) { SetSchemaValue(m_ptr, "CBreakableStageHelper", "m_nCurrentStage", false, value); }
    int32_t GetStageCount() const { return GetSchemaValue<int32_t>(m_ptr, "CBreakableStageHelper", "m_nStageCount"); }
    void SetStageCount(int32_t value) { SetSchemaValue(m_ptr, "CBreakableStageHelper", "m_nStageCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif