#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseFire::GCBaseFire(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseFire::GCBaseFire(void *ptr) {
    m_ptr = ptr;
}
float GCBaseFire::GetScale() const {
    return GetSchemaValue<float>(m_ptr, "CBaseFire", "m_flScale");
}
void GCBaseFire::SetScale(float value) {
    SetSchemaValue(m_ptr, "CBaseFire", "m_flScale", false, value);
}
float GCBaseFire::GetStartScale() const {
    return GetSchemaValue<float>(m_ptr, "CBaseFire", "m_flStartScale");
}
void GCBaseFire::SetStartScale(float value) {
    SetSchemaValue(m_ptr, "CBaseFire", "m_flStartScale", false, value);
}
float GCBaseFire::GetScaleTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseFire", "m_flScaleTime");
}
void GCBaseFire::SetScaleTime(float value) {
    SetSchemaValue(m_ptr, "CBaseFire", "m_flScaleTime", false, value);
}
uint32_t GCBaseFire::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBaseFire", "m_nFlags");
}
void GCBaseFire::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "CBaseFire", "m_nFlags", false, value);
}
std::string GCBaseFire::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseFire::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCBaseFire::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCBaseFire::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseFire(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseFire>("CBaseFire")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Scale", &GCBaseFire::GetScale, &GCBaseFire::SetScale)
        .addProperty("StartScale", &GCBaseFire::GetStartScale, &GCBaseFire::SetStartScale)
        .addProperty("ScaleTime", &GCBaseFire::GetScaleTime, &GCBaseFire::SetScaleTime)
        .addProperty("Flags", &GCBaseFire::GetFlags, &GCBaseFire::SetFlags)
        .addProperty("Parent", &GCBaseFire::GetParent, &GCBaseFire::SetParent)
        .addFunction("ToPtr", &GCBaseFire::ToPtr)
        .addFunction("IsValid", &GCBaseFire::IsValid)
        .endClass();
}