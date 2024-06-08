class GCGameGibManager;

#ifndef _gccgamegibmanager_h
#define _gccgamegibmanager_h

#include "../../../scripting.h"




class GCGameGibManager
{
private:
    void *m_ptr;

public:
    GCGameGibManager() {}
    GCGameGibManager(void *ptr) : m_ptr(ptr) {}

    bool GetAllowNewGibs() const { return GetSchemaValue<bool>(m_ptr, "CGameGibManager", "m_bAllowNewGibs"); }
    void SetAllowNewGibs(bool value) { SetSchemaValue(m_ptr, "CGameGibManager", "m_bAllowNewGibs", false, value); }
    int32_t GetCurrentMaxPieces() const { return GetSchemaValue<int32_t>(m_ptr, "CGameGibManager", "m_iCurrentMaxPieces"); }
    void SetCurrentMaxPieces(int32_t value) { SetSchemaValue(m_ptr, "CGameGibManager", "m_iCurrentMaxPieces", false, value); }
    int32_t GetMaxPieces() const { return GetSchemaValue<int32_t>(m_ptr, "CGameGibManager", "m_iMaxPieces"); }
    void SetMaxPieces(int32_t value) { SetSchemaValue(m_ptr, "CGameGibManager", "m_iMaxPieces", false, value); }
    int32_t GetLastFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CGameGibManager", "m_iLastFrame"); }
    void SetLastFrame(int32_t value) { SetSchemaValue(m_ptr, "CGameGibManager", "m_iLastFrame", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif