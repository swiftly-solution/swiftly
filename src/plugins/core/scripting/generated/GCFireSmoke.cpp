#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFireSmoke::GCFireSmoke(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFireSmoke::GCFireSmoke(void *ptr) {
    m_ptr = ptr;
}
int32_t GCFireSmoke::GetFlameModelIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFireSmoke", "m_nFlameModelIndex");
}
void GCFireSmoke::SetFlameModelIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CFireSmoke", "m_nFlameModelIndex", false, value);
}
int32_t GCFireSmoke::GetFlameFromAboveModelIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFireSmoke", "m_nFlameFromAboveModelIndex");
}
void GCFireSmoke::SetFlameFromAboveModelIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CFireSmoke", "m_nFlameFromAboveModelIndex", false, value);
}
std::string GCFireSmoke::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFireSmoke::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFire GCFireSmoke::GetParent() const {
    GCBaseFire value(m_ptr);
    return value;
}
void GCFireSmoke::SetParent(GCBaseFire value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFireSmoke(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFireSmoke>("CFireSmoke")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FlameModelIndex", &GCFireSmoke::GetFlameModelIndex, &GCFireSmoke::SetFlameModelIndex)
        .addProperty("FlameFromAboveModelIndex", &GCFireSmoke::GetFlameFromAboveModelIndex, &GCFireSmoke::SetFlameFromAboveModelIndex)
        .addProperty("Parent", &GCFireSmoke::GetParent, &GCFireSmoke::SetParent)
        .addFunction("ToPtr", &GCFireSmoke::ToPtr)
        .addFunction("IsValid", &GCFireSmoke::IsValid)
        .endClass();
}