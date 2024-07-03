#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRotButton::GCRotButton(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRotButton::GCRotButton(void *ptr) {
    m_ptr = ptr;
}
std::string GCRotButton::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRotButton::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseButton GCRotButton::GetParent() const {
    GCBaseButton value(m_ptr);
    return value;
}
void GCRotButton::SetParent(GCBaseButton value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRotButton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRotButton>("CRotButton")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCRotButton::GetParent, &GCRotButton::SetParent)
        .addFunction("ToPtr", &GCRotButton::ToPtr)
        .addFunction("IsValid", &GCRotButton::IsValid)
        .endClass();
}