#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEntComponentInfo_t::GEntComponentInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEntComponentInfo_t::GEntComponentInfo_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEntComponentInfo_t::GetName() const {
    return GetSchemaValuePtr<char>(m_ptr, "EntComponentInfo_t", "m_pName");
}
void GEntComponentInfo_t::SetName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "EntComponentInfo_t", "m_pName", true, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size());
}
std::string GEntComponentInfo_t::GetCPPClassname() const {
    return GetSchemaValuePtr<char>(m_ptr, "EntComponentInfo_t", "m_pCPPClassname");
}
void GEntComponentInfo_t::SetCPPClassname(std::string value) {
    WriteSchemaPtrValue(m_ptr, "EntComponentInfo_t", "m_pCPPClassname", true, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size());
}
std::string GEntComponentInfo_t::GetNetworkDataReferencedDescription() const {
    return GetSchemaValuePtr<char>(m_ptr, "EntComponentInfo_t", "m_pNetworkDataReferencedDescription");
}
void GEntComponentInfo_t::SetNetworkDataReferencedDescription(std::string value) {
    WriteSchemaPtrValue(m_ptr, "EntComponentInfo_t", "m_pNetworkDataReferencedDescription", true, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size());
}
std::string GEntComponentInfo_t::GetNetworkDataReferencedPtrPropDescription() const {
    return GetSchemaValuePtr<char>(m_ptr, "EntComponentInfo_t", "m_pNetworkDataReferencedPtrPropDescription");
}
void GEntComponentInfo_t::SetNetworkDataReferencedPtrPropDescription(std::string value) {
    WriteSchemaPtrValue(m_ptr, "EntComponentInfo_t", "m_pNetworkDataReferencedPtrPropDescription", true, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size());
}
int32_t GEntComponentInfo_t::GetRuntimeIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "EntComponentInfo_t", "m_nRuntimeIndex");
}
void GEntComponentInfo_t::SetRuntimeIndex(int32_t value) {
    SetSchemaValue(m_ptr, "EntComponentInfo_t", "m_nRuntimeIndex", true, value);
}
uint32_t GEntComponentInfo_t::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "EntComponentInfo_t", "m_nFlags");
}
void GEntComponentInfo_t::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "EntComponentInfo_t", "m_nFlags", true, value);
}
GCEntityComponentHelper GEntComponentInfo_t::GetBaseClassComponentHelper() const {
    GCEntityComponentHelper value(*GetSchemaValuePtr<void*>(m_ptr, "EntComponentInfo_t", "m_pBaseClassComponentHelper"));
    return value;
}
void GEntComponentInfo_t::SetBaseClassComponentHelper(GCEntityComponentHelper* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'BaseClassComponentHelper' is not possible.\n");
}
std::string GEntComponentInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEntComponentInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEntComponentInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntComponentInfo_t>("EntComponentInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GEntComponentInfo_t::GetName, &GEntComponentInfo_t::SetName)
        .addProperty("CPPClassname", &GEntComponentInfo_t::GetCPPClassname, &GEntComponentInfo_t::SetCPPClassname)
        .addProperty("NetworkDataReferencedDescription", &GEntComponentInfo_t::GetNetworkDataReferencedDescription, &GEntComponentInfo_t::SetNetworkDataReferencedDescription)
        .addProperty("NetworkDataReferencedPtrPropDescription", &GEntComponentInfo_t::GetNetworkDataReferencedPtrPropDescription, &GEntComponentInfo_t::SetNetworkDataReferencedPtrPropDescription)
        .addProperty("RuntimeIndex", &GEntComponentInfo_t::GetRuntimeIndex, &GEntComponentInfo_t::SetRuntimeIndex)
        .addProperty("Flags", &GEntComponentInfo_t::GetFlags, &GEntComponentInfo_t::SetFlags)
        .addProperty("BaseClassComponentHelper", &GEntComponentInfo_t::GetBaseClassComponentHelper, &GEntComponentInfo_t::SetBaseClassComponentHelper)
        .addFunction("ToPtr", &GEntComponentInfo_t::ToPtr)
        .addFunction("IsValid", &GEntComponentInfo_t::IsValid)
        .endClass();
}