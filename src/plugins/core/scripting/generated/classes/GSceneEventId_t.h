class GSceneEventId_t;

#ifndef _gcsceneeventid_t_h
#define _gcsceneeventid_t_h

#include "../../../scripting.h"




class GSceneEventId_t
{
private:
    void *m_ptr;

public:
    GSceneEventId_t() {}
    GSceneEventId_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetValue() const { return GetSchemaValue<uint32_t>(m_ptr, "SceneEventId_t", "m_Value"); }
    void SetValue(uint32_t value) { SetSchemaValue(m_ptr, "SceneEventId_t", "m_Value", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif