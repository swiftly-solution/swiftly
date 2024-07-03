#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMaterialDrawDescriptor::GCMaterialDrawDescriptor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMaterialDrawDescriptor::GCMaterialDrawDescriptor(void *ptr) {
    m_ptr = ptr;
}
float GCMaterialDrawDescriptor::GetUvDensity() const {
    return GetSchemaValue<float>(m_ptr, "CMaterialDrawDescriptor", "m_flUvDensity");
}
void GCMaterialDrawDescriptor::SetUvDensity(float value) {
    SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_flUvDensity", false, value);
}
Vector GCMaterialDrawDescriptor::GetTintColor() const {
    return GetSchemaValue<Vector>(m_ptr, "CMaterialDrawDescriptor", "m_vTintColor");
}
void GCMaterialDrawDescriptor::SetTintColor(Vector value) {
    SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_vTintColor", false, value);
}
float GCMaterialDrawDescriptor::GetAlpha() const {
    return GetSchemaValue<float>(m_ptr, "CMaterialDrawDescriptor", "m_flAlpha");
}
void GCMaterialDrawDescriptor::SetAlpha(float value) {
    SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_flAlpha", false, value);
}
uint32_t GCMaterialDrawDescriptor::GetFirstMeshlet() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CMaterialDrawDescriptor", "m_nFirstMeshlet");
}
void GCMaterialDrawDescriptor::SetFirstMeshlet(uint32_t value) {
    SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nFirstMeshlet", false, value);
}
uint16_t GCMaterialDrawDescriptor::GetNumMeshlets() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CMaterialDrawDescriptor", "m_nNumMeshlets");
}
void GCMaterialDrawDescriptor::SetNumMeshlets(uint16_t value) {
    SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nNumMeshlets", false, value);
}
uint64_t GCMaterialDrawDescriptor::GetPrimitiveType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CMaterialDrawDescriptor", "m_nPrimitiveType");
}
void GCMaterialDrawDescriptor::SetPrimitiveType(uint64_t value) {
    SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nPrimitiveType", false, value);
}
int32_t GCMaterialDrawDescriptor::GetBaseVertex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMaterialDrawDescriptor", "m_nBaseVertex");
}
void GCMaterialDrawDescriptor::SetBaseVertex(int32_t value) {
    SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nBaseVertex", false, value);
}
int32_t GCMaterialDrawDescriptor::GetVertexCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMaterialDrawDescriptor", "m_nVertexCount");
}
void GCMaterialDrawDescriptor::SetVertexCount(int32_t value) {
    SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nVertexCount", false, value);
}
int32_t GCMaterialDrawDescriptor::GetStartIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMaterialDrawDescriptor", "m_nStartIndex");
}
void GCMaterialDrawDescriptor::SetStartIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nStartIndex", false, value);
}
int32_t GCMaterialDrawDescriptor::GetIndexCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMaterialDrawDescriptor", "m_nIndexCount");
}
void GCMaterialDrawDescriptor::SetIndexCount(int32_t value) {
    SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nIndexCount", false, value);
}
GCRenderBufferBinding GCMaterialDrawDescriptor::GetIndexBuffer() const {
    GCRenderBufferBinding value(GetSchemaPtr(m_ptr, "CMaterialDrawDescriptor", "m_indexBuffer"));
    return value;
}
void GCMaterialDrawDescriptor::SetIndexBuffer(GCRenderBufferBinding value) {
    SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_indexBuffer", false, value);
}
std::string GCMaterialDrawDescriptor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMaterialDrawDescriptor::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMaterialDrawDescriptor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMaterialDrawDescriptor>("CMaterialDrawDescriptor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("UvDensity", &GCMaterialDrawDescriptor::GetUvDensity, &GCMaterialDrawDescriptor::SetUvDensity)
        .addProperty("TintColor", &GCMaterialDrawDescriptor::GetTintColor, &GCMaterialDrawDescriptor::SetTintColor)
        .addProperty("Alpha", &GCMaterialDrawDescriptor::GetAlpha, &GCMaterialDrawDescriptor::SetAlpha)
        .addProperty("FirstMeshlet", &GCMaterialDrawDescriptor::GetFirstMeshlet, &GCMaterialDrawDescriptor::SetFirstMeshlet)
        .addProperty("NumMeshlets", &GCMaterialDrawDescriptor::GetNumMeshlets, &GCMaterialDrawDescriptor::SetNumMeshlets)
        .addProperty("PrimitiveType", &GCMaterialDrawDescriptor::GetPrimitiveType, &GCMaterialDrawDescriptor::SetPrimitiveType)
        .addProperty("BaseVertex", &GCMaterialDrawDescriptor::GetBaseVertex, &GCMaterialDrawDescriptor::SetBaseVertex)
        .addProperty("VertexCount", &GCMaterialDrawDescriptor::GetVertexCount, &GCMaterialDrawDescriptor::SetVertexCount)
        .addProperty("StartIndex", &GCMaterialDrawDescriptor::GetStartIndex, &GCMaterialDrawDescriptor::SetStartIndex)
        .addProperty("IndexCount", &GCMaterialDrawDescriptor::GetIndexCount, &GCMaterialDrawDescriptor::SetIndexCount)
        .addProperty("IndexBuffer", &GCMaterialDrawDescriptor::GetIndexBuffer, &GCMaterialDrawDescriptor::SetIndexBuffer)
        .addFunction("ToPtr", &GCMaterialDrawDescriptor::ToPtr)
        .addFunction("IsValid", &GCMaterialDrawDescriptor::IsValid)
        .endClass();
}