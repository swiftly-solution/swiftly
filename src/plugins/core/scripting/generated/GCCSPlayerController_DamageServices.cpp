#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayerController_DamageServices::GCCSPlayerController_DamageServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayerController_DamageServices::GCCSPlayerController_DamageServices(void *ptr) {
    m_ptr = ptr;
}
int32_t GCCSPlayerController_DamageServices::GetSendUpdate() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_DamageServices", "m_nSendUpdate");
}
void GCCSPlayerController_DamageServices::SetSendUpdate(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_DamageServices", "m_nSendUpdate", false, value);
}
std::vector<GCDamageRecord> GCCSPlayerController_DamageServices::GetDamageList() const {
    CUtlVector<GCDamageRecord>* vec = GetSchemaValue<CUtlVector<GCDamageRecord>*>(m_ptr, "CCSPlayerController_DamageServices", "m_DamageList"); std::vector<GCDamageRecord> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSPlayerController_DamageServices::SetDamageList(std::vector<GCDamageRecord> value) {
    SetSchemaValueCUtlVector<GCDamageRecord>(m_ptr, "CCSPlayerController_DamageServices", "m_DamageList", false, value);
}
std::string GCCSPlayerController_DamageServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayerController_DamageServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerControllerComponent GCCSPlayerController_DamageServices::GetParent() const {
    GCPlayerControllerComponent value(m_ptr);
    return value;
}
void GCCSPlayerController_DamageServices::SetParent(GCPlayerControllerComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayerController_DamageServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerController_DamageServices>("CCSPlayerController_DamageServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SendUpdate", &GCCSPlayerController_DamageServices::GetSendUpdate, &GCCSPlayerController_DamageServices::SetSendUpdate)
        .addProperty("DamageList", &GCCSPlayerController_DamageServices::GetDamageList, &GCCSPlayerController_DamageServices::SetDamageList)
        .addProperty("Parent", &GCCSPlayerController_DamageServices::GetParent, &GCCSPlayerController_DamageServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayerController_DamageServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayerController_DamageServices::IsValid)
        .endClass();
}