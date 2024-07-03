#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVsInputSignatureElement_t::GVsInputSignatureElement_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVsInputSignatureElement_t::GVsInputSignatureElement_t(void *ptr) {
    m_ptr = ptr;
}
std::string GVsInputSignatureElement_t::GetName() const {
    return GetSchemaValuePtr<char>(m_ptr, "VsInputSignatureElement_t", "m_pName");
}
void GVsInputSignatureElement_t::SetName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "VsInputSignatureElement_t", "m_pName", true, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 64);
}
std::string GVsInputSignatureElement_t::GetSemantic() const {
    return GetSchemaValuePtr<char>(m_ptr, "VsInputSignatureElement_t", "m_pSemantic");
}
void GVsInputSignatureElement_t::SetSemantic(std::string value) {
    WriteSchemaPtrValue(m_ptr, "VsInputSignatureElement_t", "m_pSemantic", true, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 64);
}
std::string GVsInputSignatureElement_t::GetD3DSemanticName() const {
    return GetSchemaValuePtr<char>(m_ptr, "VsInputSignatureElement_t", "m_pD3DSemanticName");
}
void GVsInputSignatureElement_t::SetD3DSemanticName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "VsInputSignatureElement_t", "m_pD3DSemanticName", true, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 64);
}
int32_t GVsInputSignatureElement_t::GetD3DSemanticIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "VsInputSignatureElement_t", "m_nD3DSemanticIndex");
}
void GVsInputSignatureElement_t::SetD3DSemanticIndex(int32_t value) {
    SetSchemaValue(m_ptr, "VsInputSignatureElement_t", "m_nD3DSemanticIndex", true, value);
}
std::string GVsInputSignatureElement_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVsInputSignatureElement_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVsInputSignatureElement_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVsInputSignatureElement_t>("VsInputSignatureElement_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GVsInputSignatureElement_t::GetName, &GVsInputSignatureElement_t::SetName)
        .addProperty("Semantic", &GVsInputSignatureElement_t::GetSemantic, &GVsInputSignatureElement_t::SetSemantic)
        .addProperty("D3DSemanticName", &GVsInputSignatureElement_t::GetD3DSemanticName, &GVsInputSignatureElement_t::SetD3DSemanticName)
        .addProperty("D3DSemanticIndex", &GVsInputSignatureElement_t::GetD3DSemanticIndex, &GVsInputSignatureElement_t::SetD3DSemanticIndex)
        .addFunction("ToPtr", &GVsInputSignatureElement_t::ToPtr)
        .addFunction("IsValid", &GVsInputSignatureElement_t::IsValid)
        .endClass();
}