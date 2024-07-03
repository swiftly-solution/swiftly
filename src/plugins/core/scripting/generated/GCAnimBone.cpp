#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimBone::GCAnimBone(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimBone::GCAnimBone(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimBone::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimBone", "m_name");
}
void GCAnimBone::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimBone", "m_name", false, value);
}
int32_t GCAnimBone::GetParent() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimBone", "m_parent");
}
void GCAnimBone::SetParent(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimBone", "m_parent", false, value);
}
Vector GCAnimBone::GetPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimBone", "m_pos");
}
void GCAnimBone::SetPos(Vector value) {
    SetSchemaValue(m_ptr, "CAnimBone", "m_pos", false, value);
}
float GCAnimBone::GetScale() const {
    return GetSchemaValue<float>(m_ptr, "CAnimBone", "m_scale");
}
void GCAnimBone::SetScale(float value) {
    SetSchemaValue(m_ptr, "CAnimBone", "m_scale", false, value);
}
int32_t GCAnimBone::GetFlags() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimBone", "m_flags");
}
void GCAnimBone::SetFlags(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimBone", "m_flags", false, value);
}
std::string GCAnimBone::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimBone::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimBone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimBone>("CAnimBone")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimBone::GetName, &GCAnimBone::SetName)
        .addProperty("Parent", &GCAnimBone::GetParent, &GCAnimBone::SetParent)
        .addProperty("Pos", &GCAnimBone::GetPos, &GCAnimBone::SetPos)
        .addProperty("Scale", &GCAnimBone::GetScale, &GCAnimBone::SetScale)
        .addProperty("Flags", &GCAnimBone::GetFlags, &GCAnimBone::SetFlags)
        .addFunction("ToPtr", &GCAnimBone::ToPtr)
        .addFunction("IsValid", &GCAnimBone::IsValid)
        .endClass();
}