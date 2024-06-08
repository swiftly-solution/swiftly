class GCGameText;

#ifndef _gccgametext_h
#define _gccgametext_h

#include "../../../scripting.h"


#include "Ghudtextparms_t.h"

class GCGameText
{
private:
    void *m_ptr;

public:
    GCGameText() {}
    GCGameText(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetMessage() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CGameText", "m_iszMessage"); }
    void SetMessage(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CGameText", "m_iszMessage", false, value); }
    Ghudtextparms_t GetTextParms() const { return GetSchemaValue<Ghudtextparms_t>(m_ptr, "CGameText", "m_textParms"); }
    void SetTextParms(Ghudtextparms_t value) { SetSchemaValue(m_ptr, "CGameText", "m_textParms", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif