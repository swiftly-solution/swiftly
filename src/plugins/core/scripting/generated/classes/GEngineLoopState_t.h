class GEngineLoopState_t;

#ifndef _gcengineloopstate_t_h
#define _gcengineloopstate_t_h

#include "../../../scripting.h"




class GEngineLoopState_t
{
private:
    void *m_ptr;

public:
    GEngineLoopState_t() {}
    GEngineLoopState_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetPlatWindowWidth() const { return GetSchemaValue<int32_t>(m_ptr, "EngineLoopState_t", "m_nPlatWindowWidth"); }
    void SetPlatWindowWidth(int32_t value) { SetSchemaValue(m_ptr, "EngineLoopState_t", "m_nPlatWindowWidth", true, value); }
    int32_t GetPlatWindowHeight() const { return GetSchemaValue<int32_t>(m_ptr, "EngineLoopState_t", "m_nPlatWindowHeight"); }
    void SetPlatWindowHeight(int32_t value) { SetSchemaValue(m_ptr, "EngineLoopState_t", "m_nPlatWindowHeight", true, value); }
    int32_t GetRenderWidth() const { return GetSchemaValue<int32_t>(m_ptr, "EngineLoopState_t", "m_nRenderWidth"); }
    void SetRenderWidth(int32_t value) { SetSchemaValue(m_ptr, "EngineLoopState_t", "m_nRenderWidth", true, value); }
    int32_t GetRenderHeight() const { return GetSchemaValue<int32_t>(m_ptr, "EngineLoopState_t", "m_nRenderHeight"); }
    void SetRenderHeight(int32_t value) { SetSchemaValue(m_ptr, "EngineLoopState_t", "m_nRenderHeight", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif