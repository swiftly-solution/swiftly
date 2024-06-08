class GCCommentarySystem;

#ifndef _gcccommentarysystem_h
#define _gcccommentarysystem_h

#include "../../../scripting.h"




class GCCommentarySystem
{
private:
    void *m_ptr;

public:
    GCCommentarySystem() {}
    GCCommentarySystem(void *ptr) : m_ptr(ptr) {}

    bool GetCommentaryConvarsChanging() const { return GetSchemaValue<bool>(m_ptr, "CCommentarySystem", "m_bCommentaryConvarsChanging"); }
    void SetCommentaryConvarsChanging(bool value) { SetSchemaValue(m_ptr, "CCommentarySystem", "m_bCommentaryConvarsChanging", false, value); }
    bool GetCommentaryEnabledMidGame() const { return GetSchemaValue<bool>(m_ptr, "CCommentarySystem", "m_bCommentaryEnabledMidGame"); }
    void SetCommentaryEnabledMidGame(bool value) { SetSchemaValue(m_ptr, "CCommentarySystem", "m_bCommentaryEnabledMidGame", false, value); }
    int32_t GetTeleportStage() const { return GetSchemaValue<int32_t>(m_ptr, "CCommentarySystem", "m_iTeleportStage"); }
    void SetTeleportStage(int32_t value) { SetSchemaValue(m_ptr, "CCommentarySystem", "m_iTeleportStage", false, value); }
    bool GetCheatState() const { return GetSchemaValue<bool>(m_ptr, "CCommentarySystem", "m_bCheatState"); }
    void SetCheatState(bool value) { SetSchemaValue(m_ptr, "CCommentarySystem", "m_bCheatState", false, value); }
    bool GetIsFirstSpawnGroupToLoad() const { return GetSchemaValue<bool>(m_ptr, "CCommentarySystem", "m_bIsFirstSpawnGroupToLoad"); }
    void SetIsFirstSpawnGroupToLoad(bool value) { SetSchemaValue(m_ptr, "CCommentarySystem", "m_bIsFirstSpawnGroupToLoad", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif