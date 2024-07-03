#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHandleDummy::GCHandleDummy(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHandleDummy::GCHandleDummy(void *ptr) {
    m_ptr = ptr;
}
std::string GCHandleDummy::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHandleDummy::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCHandleDummy::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCHandleDummy::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHandleDummy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHandleDummy>("CHandleDummy")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCHandleDummy::GetParent, &GCHandleDummy::SetParent)
        .addFunction("ToPtr", &GCHandleDummy::ToPtr)
        .addFunction("IsValid", &GCHandleDummy::IsValid)
        .endClass();
}