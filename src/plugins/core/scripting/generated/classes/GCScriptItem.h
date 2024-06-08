class GCScriptItem;

#ifndef _gccscriptitem_h
#define _gccscriptitem_h

#include "../../../scripting.h"




class GCScriptItem
{
private:
    void *m_ptr;

public:
    GCScriptItem() {}
    GCScriptItem(void *ptr) : m_ptr(ptr) {}

    MoveType_t GetMoveTypeOverride() const { return GetSchemaValue<MoveType_t>(m_ptr, "CScriptItem", "m_MoveTypeOverride"); }
    void SetMoveTypeOverride(MoveType_t value) { SetSchemaValue(m_ptr, "CScriptItem", "m_MoveTypeOverride", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif