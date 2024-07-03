#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimDecoder::GCAnimDecoder(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimDecoder::GCAnimDecoder(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimDecoder::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimDecoder", "m_szName");
}
void GCAnimDecoder::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimDecoder", "m_szName", false, value);
}
int32_t GCAnimDecoder::GetVersion() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimDecoder", "m_nVersion");
}
void GCAnimDecoder::SetVersion(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimDecoder", "m_nVersion", false, value);
}
int32_t GCAnimDecoder::GetType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimDecoder", "m_nType");
}
void GCAnimDecoder::SetType(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimDecoder", "m_nType", false, value);
}
std::string GCAnimDecoder::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimDecoder::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimDecoder(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimDecoder>("CAnimDecoder")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimDecoder::GetName, &GCAnimDecoder::SetName)
        .addProperty("Version", &GCAnimDecoder::GetVersion, &GCAnimDecoder::SetVersion)
        .addProperty("Type", &GCAnimDecoder::GetType, &GCAnimDecoder::SetType)
        .addFunction("ToPtr", &GCAnimDecoder::ToPtr)
        .addFunction("IsValid", &GCAnimDecoder::IsValid)
        .endClass();
}