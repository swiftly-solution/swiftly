class GSceneViewId_t;

#ifndef _gcsceneviewid_t_h
#define _gcsceneviewid_t_h

#include "../../../scripting.h"




class GSceneViewId_t
{
private:
    void *m_ptr;

public:
    GSceneViewId_t() {}
    GSceneViewId_t(void *ptr) : m_ptr(ptr) {}

    uint64_t GetViewId() const { return GetSchemaValue<uint64_t>(m_ptr, "SceneViewId_t", "m_nViewId"); }
    void SetViewId(uint64_t value) { SetSchemaValue(m_ptr, "SceneViewId_t", "m_nViewId", true, value); }
    uint64_t GetFrameCount() const { return GetSchemaValue<uint64_t>(m_ptr, "SceneViewId_t", "m_nFrameCount"); }
    void SetFrameCount(uint64_t value) { SetSchemaValue(m_ptr, "SceneViewId_t", "m_nFrameCount", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif