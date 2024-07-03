#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSSDSMsg_ViewTarget::GCSSDSMsg_ViewTarget(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSSDSMsg_ViewTarget::GCSSDSMsg_ViewTarget(void *ptr) {
    m_ptr = ptr;
}
std::string GCSSDSMsg_ViewTarget::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSSDSMsg_ViewTarget", "m_Name").Get();
}
void GCSSDSMsg_ViewTarget::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_Name", false, CUtlString(value.c_str()));
}
uint64_t GCSSDSMsg_ViewTarget::GetTextureId() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_TextureId");
}
void GCSSDSMsg_ViewTarget::SetTextureId(uint64_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_TextureId", false, value);
}
int32_t GCSSDSMsg_ViewTarget::GetWidth() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nWidth");
}
void GCSSDSMsg_ViewTarget::SetWidth(int32_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nWidth", false, value);
}
int32_t GCSSDSMsg_ViewTarget::GetHeight() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nHeight");
}
void GCSSDSMsg_ViewTarget::SetHeight(int32_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nHeight", false, value);
}
int32_t GCSSDSMsg_ViewTarget::GetRequestedWidth() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nRequestedWidth");
}
void GCSSDSMsg_ViewTarget::SetRequestedWidth(int32_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nRequestedWidth", false, value);
}
int32_t GCSSDSMsg_ViewTarget::GetRequestedHeight() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nRequestedHeight");
}
void GCSSDSMsg_ViewTarget::SetRequestedHeight(int32_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nRequestedHeight", false, value);
}
int32_t GCSSDSMsg_ViewTarget::GetNumMipLevels() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nNumMipLevels");
}
void GCSSDSMsg_ViewTarget::SetNumMipLevels(int32_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nNumMipLevels", false, value);
}
int32_t GCSSDSMsg_ViewTarget::GetDepth() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nDepth");
}
void GCSSDSMsg_ViewTarget::SetDepth(int32_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nDepth", false, value);
}
int32_t GCSSDSMsg_ViewTarget::GetMultisampleNumSamples() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nMultisampleNumSamples");
}
void GCSSDSMsg_ViewTarget::SetMultisampleNumSamples(int32_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nMultisampleNumSamples", false, value);
}
int32_t GCSSDSMsg_ViewTarget::GetFormat() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nFormat");
}
void GCSSDSMsg_ViewTarget::SetFormat(int32_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nFormat", false, value);
}
std::string GCSSDSMsg_ViewTarget::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSSDSMsg_ViewTarget::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSSDSMsg_ViewTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_ViewTarget>("CSSDSMsg_ViewTarget")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCSSDSMsg_ViewTarget::GetName, &GCSSDSMsg_ViewTarget::SetName)
        .addProperty("TextureId", &GCSSDSMsg_ViewTarget::GetTextureId, &GCSSDSMsg_ViewTarget::SetTextureId)
        .addProperty("Width", &GCSSDSMsg_ViewTarget::GetWidth, &GCSSDSMsg_ViewTarget::SetWidth)
        .addProperty("Height", &GCSSDSMsg_ViewTarget::GetHeight, &GCSSDSMsg_ViewTarget::SetHeight)
        .addProperty("RequestedWidth", &GCSSDSMsg_ViewTarget::GetRequestedWidth, &GCSSDSMsg_ViewTarget::SetRequestedWidth)
        .addProperty("RequestedHeight", &GCSSDSMsg_ViewTarget::GetRequestedHeight, &GCSSDSMsg_ViewTarget::SetRequestedHeight)
        .addProperty("NumMipLevels", &GCSSDSMsg_ViewTarget::GetNumMipLevels, &GCSSDSMsg_ViewTarget::SetNumMipLevels)
        .addProperty("Depth", &GCSSDSMsg_ViewTarget::GetDepth, &GCSSDSMsg_ViewTarget::SetDepth)
        .addProperty("MultisampleNumSamples", &GCSSDSMsg_ViewTarget::GetMultisampleNumSamples, &GCSSDSMsg_ViewTarget::SetMultisampleNumSamples)
        .addProperty("Format", &GCSSDSMsg_ViewTarget::GetFormat, &GCSSDSMsg_ViewTarget::SetFormat)
        .addFunction("ToPtr", &GCSSDSMsg_ViewTarget::ToPtr)
        .addFunction("IsValid", &GCSSDSMsg_ViewTarget::IsValid)
        .endClass();
}