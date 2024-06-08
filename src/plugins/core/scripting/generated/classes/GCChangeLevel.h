class GCChangeLevel;

#ifndef _gccchangelevel_h
#define _gccchangelevel_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCChangeLevel
{
private:
    void *m_ptr;

public:
    GCChangeLevel() {}
    GCChangeLevel(void *ptr) : m_ptr(ptr) {}

    CUtlString GetMapName() const { return GetSchemaValue<CUtlString>(m_ptr, "CChangeLevel", "m_sMapName"); }
    void SetMapName(CUtlString value) { SetSchemaValue(m_ptr, "CChangeLevel", "m_sMapName", false, value); }
    CUtlString GetLandmarkName() const { return GetSchemaValue<CUtlString>(m_ptr, "CChangeLevel", "m_sLandmarkName"); }
    void SetLandmarkName(CUtlString value) { SetSchemaValue(m_ptr, "CChangeLevel", "m_sLandmarkName", false, value); }
    GCEntityIOOutput GetOnChangeLevel() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CChangeLevel", "m_OnChangeLevel"); }
    void SetOnChangeLevel(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CChangeLevel", "m_OnChangeLevel", false, value); }
    bool GetTouched() const { return GetSchemaValue<bool>(m_ptr, "CChangeLevel", "m_bTouched"); }
    void SetTouched(bool value) { SetSchemaValue(m_ptr, "CChangeLevel", "m_bTouched", false, value); }
    bool GetNoTouch() const { return GetSchemaValue<bool>(m_ptr, "CChangeLevel", "m_bNoTouch"); }
    void SetNoTouch(bool value) { SetSchemaValue(m_ptr, "CChangeLevel", "m_bNoTouch", false, value); }
    bool GetNewChapter() const { return GetSchemaValue<bool>(m_ptr, "CChangeLevel", "m_bNewChapter"); }
    void SetNewChapter(bool value) { SetSchemaValue(m_ptr, "CChangeLevel", "m_bNewChapter", false, value); }
    bool GetOnChangeLevelFired() const { return GetSchemaValue<bool>(m_ptr, "CChangeLevel", "m_bOnChangeLevelFired"); }
    void SetOnChangeLevelFired(bool value) { SetSchemaValue(m_ptr, "CChangeLevel", "m_bOnChangeLevelFired", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif