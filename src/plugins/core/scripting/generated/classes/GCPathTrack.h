class GCPathTrack;

#ifndef _gccpathtrack_h
#define _gccpathtrack_h

#include "../../../scripting.h"

#include "../types/GTrackOrientationType_t.h"
#include "GCPathTrack.h"
#include "GCEntityIOOutput.h"

class GCPathTrack
{
private:
    void *m_ptr;

public:
    GCPathTrack() {}
    GCPathTrack(void *ptr) : m_ptr(ptr) {}

    GCPathTrack* GetPnext() const { return GetSchemaValue<GCPathTrack*>(m_ptr, "CPathTrack", "m_pnext"); }
    void SetPnext(GCPathTrack* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Pnext' is not possible.\n"); }
    GCPathTrack* GetPprevious() const { return GetSchemaValue<GCPathTrack*>(m_ptr, "CPathTrack", "m_pprevious"); }
    void SetPprevious(GCPathTrack* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Pprevious' is not possible.\n"); }
    GCPathTrack* GetPaltpath() const { return GetSchemaValue<GCPathTrack*>(m_ptr, "CPathTrack", "m_paltpath"); }
    void SetPaltpath(GCPathTrack* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Paltpath' is not possible.\n"); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CPathTrack", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CPathTrack", "m_flRadius", false, value); }
    float GetLength() const { return GetSchemaValue<float>(m_ptr, "CPathTrack", "m_length"); }
    void SetLength(float value) { SetSchemaValue(m_ptr, "CPathTrack", "m_length", false, value); }
    CUtlSymbolLarge GetAltName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPathTrack", "m_altName"); }
    void SetAltName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPathTrack", "m_altName", false, value); }
    int32_t GetIterVal() const { return GetSchemaValue<int32_t>(m_ptr, "CPathTrack", "m_nIterVal"); }
    void SetIterVal(int32_t value) { SetSchemaValue(m_ptr, "CPathTrack", "m_nIterVal", false, value); }
    TrackOrientationType_t GetOrientationType() const { return GetSchemaValue<TrackOrientationType_t>(m_ptr, "CPathTrack", "m_eOrientationType"); }
    void SetOrientationType(TrackOrientationType_t value) { SetSchemaValue(m_ptr, "CPathTrack", "m_eOrientationType", false, value); }
    GCEntityIOOutput GetOnPass() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPathTrack", "m_OnPass"); }
    void SetOnPass(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPathTrack", "m_OnPass", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif