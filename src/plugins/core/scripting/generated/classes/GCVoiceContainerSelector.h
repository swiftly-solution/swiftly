class GCVoiceContainerSelector;

#ifndef _gccvoicecontainerselector_h
#define _gccvoicecontainerselector_h

#include "../../../scripting.h"

#include "../types/GPlayBackMode_t.h"


class GCVoiceContainerSelector
{
private:
    void *m_ptr;

public:
    GCVoiceContainerSelector() {}
    GCVoiceContainerSelector(void *ptr) : m_ptr(ptr) {}

    PlayBackMode_t GetMode() const { return GetSchemaValue<PlayBackMode_t>(m_ptr, "CVoiceContainerSelector", "m_mode"); }
    void SetMode(PlayBackMode_t value) { SetSchemaValue(m_ptr, "CVoiceContainerSelector", "m_mode", false, value); }
    bool GetRetrigger() const { return GetSchemaValue<bool>(m_ptr, "CVoiceContainerSelector", "m_bRetrigger"); }
    void SetRetrigger(bool value) { SetSchemaValue(m_ptr, "CVoiceContainerSelector", "m_bRetrigger", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif