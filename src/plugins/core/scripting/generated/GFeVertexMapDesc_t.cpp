#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeVertexMapDesc_t::GFeVertexMapDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeVertexMapDesc_t::GFeVertexMapDesc_t(void *ptr) {
    m_ptr = ptr;
}
std::string GFeVertexMapDesc_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "FeVertexMapDesc_t", "sName").Get();
}
void GFeVertexMapDesc_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "sName", true, CUtlString(value.c_str()));
}
uint32_t GFeVertexMapDesc_t::GetNameHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeVertexMapDesc_t", "nNameHash");
}
void GFeVertexMapDesc_t::SetNameHash(uint32_t value) {
    SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nNameHash", true, value);
}
uint32_t GFeVertexMapDesc_t::GetColor() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeVertexMapDesc_t", "nColor");
}
void GFeVertexMapDesc_t::SetColor(uint32_t value) {
    SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nColor", true, value);
}
uint32_t GFeVertexMapDesc_t::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeVertexMapDesc_t", "nFlags");
}
void GFeVertexMapDesc_t::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nFlags", true, value);
}
uint16_t GFeVertexMapDesc_t::GetVertexBase() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeVertexMapDesc_t", "nVertexBase");
}
void GFeVertexMapDesc_t::SetVertexBase(uint16_t value) {
    SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nVertexBase", true, value);
}
uint16_t GFeVertexMapDesc_t::GetVertexCount() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeVertexMapDesc_t", "nVertexCount");
}
void GFeVertexMapDesc_t::SetVertexCount(uint16_t value) {
    SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nVertexCount", true, value);
}
uint32_t GFeVertexMapDesc_t::GetMapOffset() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeVertexMapDesc_t", "nMapOffset");
}
void GFeVertexMapDesc_t::SetMapOffset(uint32_t value) {
    SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nMapOffset", true, value);
}
uint32_t GFeVertexMapDesc_t::GetNodeListOffset() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeVertexMapDesc_t", "nNodeListOffset");
}
void GFeVertexMapDesc_t::SetNodeListOffset(uint32_t value) {
    SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nNodeListOffset", true, value);
}
Vector GFeVertexMapDesc_t::GetCenterOfMass() const {
    return GetSchemaValue<Vector>(m_ptr, "FeVertexMapDesc_t", "vCenterOfMass");
}
void GFeVertexMapDesc_t::SetCenterOfMass(Vector value) {
    SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "vCenterOfMass", true, value);
}
float GFeVertexMapDesc_t::GetVolumetricSolveStrength() const {
    return GetSchemaValue<float>(m_ptr, "FeVertexMapDesc_t", "flVolumetricSolveStrength");
}
void GFeVertexMapDesc_t::SetVolumetricSolveStrength(float value) {
    SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "flVolumetricSolveStrength", true, value);
}
int16_t GFeVertexMapDesc_t::GetScaleSourceNode() const {
    return GetSchemaValue<int16_t>(m_ptr, "FeVertexMapDesc_t", "nScaleSourceNode");
}
void GFeVertexMapDesc_t::SetScaleSourceNode(int16_t value) {
    SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nScaleSourceNode", true, value);
}
uint16_t GFeVertexMapDesc_t::GetNodeListCount() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeVertexMapDesc_t", "nNodeListCount");
}
void GFeVertexMapDesc_t::SetNodeListCount(uint16_t value) {
    SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nNodeListCount", true, value);
}
std::string GFeVertexMapDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeVertexMapDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeVertexMapDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeVertexMapDesc_t>("FeVertexMapDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GFeVertexMapDesc_t::GetName, &GFeVertexMapDesc_t::SetName)
        .addProperty("NameHash", &GFeVertexMapDesc_t::GetNameHash, &GFeVertexMapDesc_t::SetNameHash)
        .addProperty("Color", &GFeVertexMapDesc_t::GetColor, &GFeVertexMapDesc_t::SetColor)
        .addProperty("Flags", &GFeVertexMapDesc_t::GetFlags, &GFeVertexMapDesc_t::SetFlags)
        .addProperty("VertexBase", &GFeVertexMapDesc_t::GetVertexBase, &GFeVertexMapDesc_t::SetVertexBase)
        .addProperty("VertexCount", &GFeVertexMapDesc_t::GetVertexCount, &GFeVertexMapDesc_t::SetVertexCount)
        .addProperty("MapOffset", &GFeVertexMapDesc_t::GetMapOffset, &GFeVertexMapDesc_t::SetMapOffset)
        .addProperty("NodeListOffset", &GFeVertexMapDesc_t::GetNodeListOffset, &GFeVertexMapDesc_t::SetNodeListOffset)
        .addProperty("CenterOfMass", &GFeVertexMapDesc_t::GetCenterOfMass, &GFeVertexMapDesc_t::SetCenterOfMass)
        .addProperty("VolumetricSolveStrength", &GFeVertexMapDesc_t::GetVolumetricSolveStrength, &GFeVertexMapDesc_t::SetVolumetricSolveStrength)
        .addProperty("ScaleSourceNode", &GFeVertexMapDesc_t::GetScaleSourceNode, &GFeVertexMapDesc_t::SetScaleSourceNode)
        .addProperty("NodeListCount", &GFeVertexMapDesc_t::GetNodeListCount, &GFeVertexMapDesc_t::SetNodeListCount)
        .addFunction("ToPtr", &GFeVertexMapDesc_t::ToPtr)
        .addFunction("IsValid", &GFeVertexMapDesc_t::IsValid)
        .endClass();
}