#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GExtraVertexStreamOverride_t::GExtraVertexStreamOverride_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GExtraVertexStreamOverride_t::GExtraVertexStreamOverride_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GExtraVertexStreamOverride_t::GetSubSceneObject() const {
    return GetSchemaValue<uint32_t>(m_ptr, "ExtraVertexStreamOverride_t", "m_nSubSceneObject");
}
void GExtraVertexStreamOverride_t::SetSubSceneObject(uint32_t value) {
    SetSchemaValue(m_ptr, "ExtraVertexStreamOverride_t", "m_nSubSceneObject", true, value);
}
uint32_t GExtraVertexStreamOverride_t::GetDrawCallIndex() const {
    return GetSchemaValue<uint32_t>(m_ptr, "ExtraVertexStreamOverride_t", "m_nDrawCallIndex");
}
void GExtraVertexStreamOverride_t::SetDrawCallIndex(uint32_t value) {
    SetSchemaValue(m_ptr, "ExtraVertexStreamOverride_t", "m_nDrawCallIndex", true, value);
}
uint64_t GExtraVertexStreamOverride_t::GetAdditionalMeshDrawPrimitiveFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ExtraVertexStreamOverride_t", "m_nAdditionalMeshDrawPrimitiveFlags");
}
void GExtraVertexStreamOverride_t::SetAdditionalMeshDrawPrimitiveFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "ExtraVertexStreamOverride_t", "m_nAdditionalMeshDrawPrimitiveFlags", true, value);
}
GCRenderBufferBinding GExtraVertexStreamOverride_t::GetExtraBufferBinding() const {
    GCRenderBufferBinding value(GetSchemaPtr(m_ptr, "ExtraVertexStreamOverride_t", "m_extraBufferBinding"));
    return value;
}
void GExtraVertexStreamOverride_t::SetExtraBufferBinding(GCRenderBufferBinding value) {
    SetSchemaValue(m_ptr, "ExtraVertexStreamOverride_t", "m_extraBufferBinding", true, value);
}
std::string GExtraVertexStreamOverride_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GExtraVertexStreamOverride_t::IsValid() {
    return (m_ptr != nullptr);
}
GBaseSceneObjectOverride_t GExtraVertexStreamOverride_t::GetParent() const {
    GBaseSceneObjectOverride_t value(m_ptr);
    return value;
}
void GExtraVertexStreamOverride_t::SetParent(GBaseSceneObjectOverride_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassExtraVertexStreamOverride_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GExtraVertexStreamOverride_t>("ExtraVertexStreamOverride_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SubSceneObject", &GExtraVertexStreamOverride_t::GetSubSceneObject, &GExtraVertexStreamOverride_t::SetSubSceneObject)
        .addProperty("DrawCallIndex", &GExtraVertexStreamOverride_t::GetDrawCallIndex, &GExtraVertexStreamOverride_t::SetDrawCallIndex)
        .addProperty("AdditionalMeshDrawPrimitiveFlags", &GExtraVertexStreamOverride_t::GetAdditionalMeshDrawPrimitiveFlags, &GExtraVertexStreamOverride_t::SetAdditionalMeshDrawPrimitiveFlags)
        .addProperty("ExtraBufferBinding", &GExtraVertexStreamOverride_t::GetExtraBufferBinding, &GExtraVertexStreamOverride_t::SetExtraBufferBinding)
        .addProperty("Parent", &GExtraVertexStreamOverride_t::GetParent, &GExtraVertexStreamOverride_t::SetParent)
        .addFunction("ToPtr", &GExtraVertexStreamOverride_t::ToPtr)
        .addFunction("IsValid", &GExtraVertexStreamOverride_t::IsValid)
        .endClass();
}