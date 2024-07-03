#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlace::GCCSPlace(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlace::GCCSPlace(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSPlace::GetName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CCSPlace", "m_name").String();
}
void GCCSPlace::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CCSPlace", "m_name", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCCSPlace::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlace::IsValid() {
    return (m_ptr != nullptr);
}
GCServerOnlyModelEntity GCCSPlace::GetParent() const {
    GCServerOnlyModelEntity value(m_ptr);
    return value;
}
void GCCSPlace::SetParent(GCServerOnlyModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlace(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlace>("CCSPlace")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCCSPlace::GetName, &GCCSPlace::SetName)
        .addProperty("Parent", &GCCSPlace::GetParent, &GCCSPlace::SetParent)
        .addFunction("ToPtr", &GCCSPlace::ToPtr)
        .addFunction("IsValid", &GCCSPlace::IsValid)
        .endClass();
}