#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMultiSource::GCMultiSource(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMultiSource::GCMultiSource(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCBaseEntity*> GCMultiSource::GetRgEntities() const {
    GCBaseEntity** outValue = GetSchemaValue<GCBaseEntity**>(m_ptr, "CMultiSource", "m_rgEntities"); std::vector<GCBaseEntity*> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMultiSource::SetRgEntities(std::vector<GCBaseEntity*> value) {
    GCBaseEntity** outValue = GetSchemaValue<GCBaseEntity**>(m_ptr, "CMultiSource", "m_rgEntities"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMultiSource", "m_rgEntities", false, outValue);
}
std::vector<int32_t> GCMultiSource::GetRgTriggered() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMultiSource", "m_rgTriggered"); std::vector<int32_t> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMultiSource::SetRgTriggered(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMultiSource", "m_rgTriggered"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMultiSource", "m_rgTriggered", false, outValue);
}
GCEntityIOOutput GCMultiSource::GetOnTrigger() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMultiSource", "m_OnTrigger"));
    return value;
}
void GCMultiSource::SetOnTrigger(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMultiSource", "m_OnTrigger", false, value);
}
int32_t GCMultiSource::GetTotal() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMultiSource", "m_iTotal");
}
void GCMultiSource::SetTotal(int32_t value) {
    SetSchemaValue(m_ptr, "CMultiSource", "m_iTotal", false, value);
}
std::string GCMultiSource::GetGlobalstate() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMultiSource", "m_globalstate").String();
}
void GCMultiSource::SetGlobalstate(std::string value) {
    SetSchemaValue(m_ptr, "CMultiSource", "m_globalstate", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCMultiSource::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMultiSource::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCMultiSource::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCMultiSource::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMultiSource(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMultiSource>("CMultiSource")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RgEntities", &GCMultiSource::GetRgEntities, &GCMultiSource::SetRgEntities)
        .addProperty("RgTriggered", &GCMultiSource::GetRgTriggered, &GCMultiSource::SetRgTriggered)
        .addProperty("OnTrigger", &GCMultiSource::GetOnTrigger, &GCMultiSource::SetOnTrigger)
        .addProperty("Total", &GCMultiSource::GetTotal, &GCMultiSource::SetTotal)
        .addProperty("Globalstate", &GCMultiSource::GetGlobalstate, &GCMultiSource::SetGlobalstate)
        .addProperty("Parent", &GCMultiSource::GetParent, &GCMultiSource::SetParent)
        .addFunction("ToPtr", &GCMultiSource::ToPtr)
        .addFunction("IsValid", &GCMultiSource::IsValid)
        .endClass();
}