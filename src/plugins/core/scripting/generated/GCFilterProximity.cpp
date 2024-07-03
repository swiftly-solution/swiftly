#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFilterProximity::GCFilterProximity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFilterProximity::GCFilterProximity(void *ptr) {
    m_ptr = ptr;
}
float GCFilterProximity::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CFilterProximity", "m_flRadius");
}
void GCFilterProximity::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CFilterProximity", "m_flRadius", false, value);
}
std::string GCFilterProximity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFilterProximity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GCFilterProximity::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GCFilterProximity::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFilterProximity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterProximity>("CFilterProximity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Radius", &GCFilterProximity::GetRadius, &GCFilterProximity::SetRadius)
        .addProperty("Parent", &GCFilterProximity::GetParent, &GCFilterProximity::SetParent)
        .addFunction("ToPtr", &GCFilterProximity::ToPtr)
        .addFunction("IsValid", &GCFilterProximity::IsValid)
        .endClass();
}