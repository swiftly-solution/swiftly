class GCTriggerSoundscape;

#ifndef _gcctriggersoundscape_h
#define _gcctriggersoundscape_h

#include "../../../scripting.h"


#include "GCEnvSoundscape.h"
#include "GCEnvSoundscapeTriggerable.h"

class GCTriggerSoundscape
{
private:
    void *m_ptr;

public:
    GCTriggerSoundscape() {}
    GCTriggerSoundscape(void *ptr) : m_ptr(ptr) {}

    GCEnvSoundscapeTriggerable* GetSoundscape() const { return GetSchemaValue<GCEnvSoundscapeTriggerable*>(m_ptr, "CTriggerSoundscape", "m_hSoundscape"); }
    void SetSoundscape(GCEnvSoundscapeTriggerable* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Soundscape' is not possible.\n"); }
    CUtlSymbolLarge GetSoundscapeName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerSoundscape", "m_SoundscapeName"); }
    void SetSoundscapeName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerSoundscape", "m_SoundscapeName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif