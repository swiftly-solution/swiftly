#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRenderBufferBinding::GCRenderBufferBinding(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRenderBufferBinding::GCRenderBufferBinding(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCRenderBufferBinding::GetBuffer() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CRenderBufferBinding", "m_hBuffer");
}
void GCRenderBufferBinding::SetBuffer(uint64_t value) {
    SetSchemaValue(m_ptr, "CRenderBufferBinding", "m_hBuffer", false, value);
}
uint32_t GCRenderBufferBinding::GetBindOffsetBytes() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CRenderBufferBinding", "m_nBindOffsetBytes");
}
void GCRenderBufferBinding::SetBindOffsetBytes(uint32_t value) {
    SetSchemaValue(m_ptr, "CRenderBufferBinding", "m_nBindOffsetBytes", false, value);
}
std::string GCRenderBufferBinding::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRenderBufferBinding::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCRenderBufferBinding(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRenderBufferBinding>("CRenderBufferBinding")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Buffer", &GCRenderBufferBinding::GetBuffer, &GCRenderBufferBinding::SetBuffer)
        .addProperty("BindOffsetBytes", &GCRenderBufferBinding::GetBindOffsetBytes, &GCRenderBufferBinding::SetBindOffsetBytes)
        .addFunction("ToPtr", &GCRenderBufferBinding::ToPtr)
        .addFunction("IsValid", &GCRenderBufferBinding::IsValid)
        .endClass();
}