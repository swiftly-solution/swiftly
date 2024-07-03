#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayer_BuyServices::GCCSPlayer_BuyServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayer_BuyServices::GCCSPlayer_BuyServices(void *ptr) {
    m_ptr = ptr;
}
std::vector<GSellbackPurchaseEntry_t> GCCSPlayer_BuyServices::GetSellbackPurchaseEntries() const {
    CUtlVector<GSellbackPurchaseEntry_t>* vec = GetSchemaValue<CUtlVector<GSellbackPurchaseEntry_t>*>(m_ptr, "CCSPlayer_BuyServices", "m_vecSellbackPurchaseEntries"); std::vector<GSellbackPurchaseEntry_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSPlayer_BuyServices::SetSellbackPurchaseEntries(std::vector<GSellbackPurchaseEntry_t> value) {
    SetSchemaValueCUtlVector<GSellbackPurchaseEntry_t>(m_ptr, "CCSPlayer_BuyServices", "m_vecSellbackPurchaseEntries", false, value);
}
std::string GCCSPlayer_BuyServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayer_BuyServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCCSPlayer_BuyServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCCSPlayer_BuyServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayer_BuyServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_BuyServices>("CCSPlayer_BuyServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SellbackPurchaseEntries", &GCCSPlayer_BuyServices::GetSellbackPurchaseEntries, &GCCSPlayer_BuyServices::SetSellbackPurchaseEntries)
        .addProperty("Parent", &GCCSPlayer_BuyServices::GetParent, &GCCSPlayer_BuyServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayer_BuyServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayer_BuyServices::IsValid)
        .endClass();
}