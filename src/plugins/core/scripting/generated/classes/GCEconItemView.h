class GCEconItemView;

#ifndef _gcceconitemview_h
#define _gcceconitemview_h

#include "../../../scripting.h"


#include "GCAttributeList.h"

class GCEconItemView
{
private:
    void *m_ptr;

public:
    GCEconItemView() {}
    GCEconItemView(void *ptr) : m_ptr(ptr) {}

    uint16_t GetItemDefinitionIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "CEconItemView", "m_iItemDefinitionIndex"); }
    void SetItemDefinitionIndex(uint16_t value) { SetSchemaValue(m_ptr, "CEconItemView", "m_iItemDefinitionIndex", false, value); }
    int32_t GetEntityQuality() const { return GetSchemaValue<int32_t>(m_ptr, "CEconItemView", "m_iEntityQuality"); }
    void SetEntityQuality(int32_t value) { SetSchemaValue(m_ptr, "CEconItemView", "m_iEntityQuality", false, value); }
    uint32_t GetEntityLevel() const { return GetSchemaValue<uint32_t>(m_ptr, "CEconItemView", "m_iEntityLevel"); }
    void SetEntityLevel(uint32_t value) { SetSchemaValue(m_ptr, "CEconItemView", "m_iEntityLevel", false, value); }
    uint64_t GetItemID() const { return GetSchemaValue<uint64_t>(m_ptr, "CEconItemView", "m_iItemID"); }
    void SetItemID(uint64_t value) { SetSchemaValue(m_ptr, "CEconItemView", "m_iItemID", false, value); }
    uint32_t GetItemIDHigh() const { return GetSchemaValue<uint32_t>(m_ptr, "CEconItemView", "m_iItemIDHigh"); }
    void SetItemIDHigh(uint32_t value) { SetSchemaValue(m_ptr, "CEconItemView", "m_iItemIDHigh", false, value); }
    uint32_t GetItemIDLow() const { return GetSchemaValue<uint32_t>(m_ptr, "CEconItemView", "m_iItemIDLow"); }
    void SetItemIDLow(uint32_t value) { SetSchemaValue(m_ptr, "CEconItemView", "m_iItemIDLow", false, value); }
    uint32_t GetAccountID() const { return GetSchemaValue<uint32_t>(m_ptr, "CEconItemView", "m_iAccountID"); }
    void SetAccountID(uint32_t value) { SetSchemaValue(m_ptr, "CEconItemView", "m_iAccountID", false, value); }
    uint32_t GetInventoryPosition() const { return GetSchemaValue<uint32_t>(m_ptr, "CEconItemView", "m_iInventoryPosition"); }
    void SetInventoryPosition(uint32_t value) { SetSchemaValue(m_ptr, "CEconItemView", "m_iInventoryPosition", false, value); }
    bool GetInitialized() const { return GetSchemaValue<bool>(m_ptr, "CEconItemView", "m_bInitialized"); }
    void SetInitialized(bool value) { SetSchemaValue(m_ptr, "CEconItemView", "m_bInitialized", false, value); }
    GCAttributeList GetAttributeList() const { return GetSchemaValue<GCAttributeList>(m_ptr, "CEconItemView", "m_AttributeList"); }
    void SetAttributeList(GCAttributeList value) { SetSchemaValue(m_ptr, "CEconItemView", "m_AttributeList", false, value); }
    GCAttributeList GetNetworkedDynamicAttributes() const { return GetSchemaValue<GCAttributeList>(m_ptr, "CEconItemView", "m_NetworkedDynamicAttributes"); }
    void SetNetworkedDynamicAttributes(GCAttributeList value) { SetSchemaValue(m_ptr, "CEconItemView", "m_NetworkedDynamicAttributes", false, value); }
    std::string GetCustomName() const { return GetSchemaValue<char*>(m_ptr, "CEconItemView", "m_szCustomName"); }
    void SetCustomName(std::string value) { SetSchemaValue(m_ptr, "CEconItemView", "m_szCustomName", false, value); }
    std::string GetCustomNameOverride() const { return GetSchemaValue<char*>(m_ptr, "CEconItemView", "m_szCustomNameOverride"); }
    void SetCustomNameOverride(std::string value) { SetSchemaValue(m_ptr, "CEconItemView", "m_szCustomNameOverride", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif