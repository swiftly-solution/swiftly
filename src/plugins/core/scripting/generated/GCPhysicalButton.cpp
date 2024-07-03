#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysicalButton::GCPhysicalButton(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysicalButton::GCPhysicalButton(void *ptr) {
    m_ptr = ptr;
}
std::string GCPhysicalButton::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysicalButton::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseButton GCPhysicalButton::GetParent() const {
    GCBaseButton value(m_ptr);
    return value;
}
void GCPhysicalButton::SetParent(GCBaseButton value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysicalButton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicalButton>("CPhysicalButton")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPhysicalButton::GetParent, &GCPhysicalButton::SetParent)
        .addFunction("ToPtr", &GCPhysicalButton::ToPtr)
        .addFunction("IsValid", &GCPhysicalButton::IsValid)
        .endClass();
}