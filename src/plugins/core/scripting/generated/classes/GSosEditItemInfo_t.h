class GSosEditItemInfo_t;

#ifndef _gcsosedititeminfo_t_h
#define _gcsosedititeminfo_t_h

#include "../../../scripting.h"

#include "../types/GSosEditItemType_t.h"


class GSosEditItemInfo_t
{
private:
    void *m_ptr;

public:
    GSosEditItemInfo_t() {}
    GSosEditItemInfo_t(void *ptr) : m_ptr(ptr) {}

    SosEditItemType_t GetItemType() const { return GetSchemaValue<SosEditItemType_t>(m_ptr, "SosEditItemInfo_t", "itemType"); }
    void SetItemType(SosEditItemType_t value) { SetSchemaValue(m_ptr, "SosEditItemInfo_t", "itemType", true, value); }
    CUtlString GetItemName() const { return GetSchemaValue<CUtlString>(m_ptr, "SosEditItemInfo_t", "itemName"); }
    void SetItemName(CUtlString value) { SetSchemaValue(m_ptr, "SosEditItemInfo_t", "itemName", true, value); }
    CUtlString GetItemTypeName() const { return GetSchemaValue<CUtlString>(m_ptr, "SosEditItemInfo_t", "itemTypeName"); }
    void SetItemTypeName(CUtlString value) { SetSchemaValue(m_ptr, "SosEditItemInfo_t", "itemTypeName", true, value); }
    CUtlString GetItemKVString() const { return GetSchemaValue<CUtlString>(m_ptr, "SosEditItemInfo_t", "itemKVString"); }
    void SetItemKVString(CUtlString value) { SetSchemaValue(m_ptr, "SosEditItemInfo_t", "itemKVString", true, value); }
    Vector2D GetItemPos() const { return GetSchemaValue<Vector2D>(m_ptr, "SosEditItemInfo_t", "itemPos"); }
    void SetItemPos(Vector2D value) { SetSchemaValue(m_ptr, "SosEditItemInfo_t", "itemPos", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif