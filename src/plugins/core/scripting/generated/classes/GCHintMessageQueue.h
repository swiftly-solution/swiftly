class GCHintMessageQueue;

#ifndef _gcchintmessagequeue_h
#define _gcchintmessagequeue_h

#include "../../../scripting.h"


#include "GCBasePlayerController.h"

class GCHintMessageQueue
{
private:
    void *m_ptr;

public:
    GCHintMessageQueue() {}
    GCHintMessageQueue(void *ptr) : m_ptr(ptr) {}

    float GetTmMessageEnd() const { return GetSchemaValue<float>(m_ptr, "CHintMessageQueue", "m_tmMessageEnd"); }
    void SetTmMessageEnd(float value) { SetSchemaValue(m_ptr, "CHintMessageQueue", "m_tmMessageEnd", false, value); }
    GCBasePlayerController* GetPlayerController() const { return GetSchemaValue<GCBasePlayerController*>(m_ptr, "CHintMessageQueue", "m_pPlayerController"); }
    void SetPlayerController(GCBasePlayerController* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerController' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif