class GCMarkupVolumeTagged_NavGame;

#ifndef _gccmarkupvolumetagged_navgame_h
#define _gccmarkupvolumetagged_navgame_h

#include "../../../scripting.h"




class GCMarkupVolumeTagged_NavGame
{
private:
    void *m_ptr;

public:
    GCMarkupVolumeTagged_NavGame() {}
    GCMarkupVolumeTagged_NavGame(void *ptr) : m_ptr(ptr) {}

    bool GetFloodFillAttribute() const { return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeTagged_NavGame", "m_bFloodFillAttribute"); }
    void SetFloodFillAttribute(bool value) { SetSchemaValue(m_ptr, "CMarkupVolumeTagged_NavGame", "m_bFloodFillAttribute", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif