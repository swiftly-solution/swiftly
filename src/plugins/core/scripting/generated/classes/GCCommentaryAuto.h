class GCCommentaryAuto;

#ifndef _gcccommentaryauto_h
#define _gcccommentaryauto_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCCommentaryAuto
{
private:
    void *m_ptr;

public:
    GCCommentaryAuto() {}
    GCCommentaryAuto(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnCommentaryNewGame() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CCommentaryAuto", "m_OnCommentaryNewGame"); }
    void SetOnCommentaryNewGame(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CCommentaryAuto", "m_OnCommentaryNewGame", false, value); }
    GCEntityIOOutput GetOnCommentaryMidGame() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CCommentaryAuto", "m_OnCommentaryMidGame"); }
    void SetOnCommentaryMidGame(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CCommentaryAuto", "m_OnCommentaryMidGame", false, value); }
    GCEntityIOOutput GetOnCommentaryMultiplayerSpawn() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CCommentaryAuto", "m_OnCommentaryMultiplayerSpawn"); }
    void SetOnCommentaryMultiplayerSpawn(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CCommentaryAuto", "m_OnCommentaryMultiplayerSpawn", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif