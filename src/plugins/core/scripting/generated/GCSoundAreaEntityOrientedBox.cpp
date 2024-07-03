#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundAreaEntityOrientedBox::GCSoundAreaEntityOrientedBox(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundAreaEntityOrientedBox::GCSoundAreaEntityOrientedBox(void *ptr) {
    m_ptr = ptr;
}
Vector GCSoundAreaEntityOrientedBox::GetMin() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundAreaEntityOrientedBox", "m_vMin");
}
void GCSoundAreaEntityOrientedBox::SetMin(Vector value) {
    SetSchemaValue(m_ptr, "CSoundAreaEntityOrientedBox", "m_vMin", false, value);
}
Vector GCSoundAreaEntityOrientedBox::GetMax() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundAreaEntityOrientedBox", "m_vMax");
}
void GCSoundAreaEntityOrientedBox::SetMax(Vector value) {
    SetSchemaValue(m_ptr, "CSoundAreaEntityOrientedBox", "m_vMax", false, value);
}
std::string GCSoundAreaEntityOrientedBox::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundAreaEntityOrientedBox::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundAreaEntityBase GCSoundAreaEntityOrientedBox::GetParent() const {
    GCSoundAreaEntityBase value(m_ptr);
    return value;
}
void GCSoundAreaEntityOrientedBox::SetParent(GCSoundAreaEntityBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundAreaEntityOrientedBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundAreaEntityOrientedBox>("CSoundAreaEntityOrientedBox")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Min", &GCSoundAreaEntityOrientedBox::GetMin, &GCSoundAreaEntityOrientedBox::SetMin)
        .addProperty("Max", &GCSoundAreaEntityOrientedBox::GetMax, &GCSoundAreaEntityOrientedBox::SetMax)
        .addProperty("Parent", &GCSoundAreaEntityOrientedBox::GetParent, &GCSoundAreaEntityOrientedBox::SetParent)
        .addFunction("ToPtr", &GCSoundAreaEntityOrientedBox::ToPtr)
        .addFunction("IsValid", &GCSoundAreaEntityOrientedBox::IsValid)
        .endClass();
}