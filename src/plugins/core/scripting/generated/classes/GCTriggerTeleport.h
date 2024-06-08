class GCTriggerTeleport;

#ifndef _gcctriggerteleport_h
#define _gcctriggerteleport_h

#include "../../../scripting.h"




class GCTriggerTeleport
{
private:
    void *m_ptr;

public:
    GCTriggerTeleport() {}
    GCTriggerTeleport(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetLandmark() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerTeleport", "m_iLandmark"); }
    void SetLandmark(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerTeleport", "m_iLandmark", false, value); }
    bool GetUseLandmarkAngles() const { return GetSchemaValue<bool>(m_ptr, "CTriggerTeleport", "m_bUseLandmarkAngles"); }
    void SetUseLandmarkAngles(bool value) { SetSchemaValue(m_ptr, "CTriggerTeleport", "m_bUseLandmarkAngles", false, value); }
    bool GetMirrorPlayer() const { return GetSchemaValue<bool>(m_ptr, "CTriggerTeleport", "m_bMirrorPlayer"); }
    void SetMirrorPlayer(bool value) { SetSchemaValue(m_ptr, "CTriggerTeleport", "m_bMirrorPlayer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif