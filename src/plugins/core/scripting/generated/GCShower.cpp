#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCShower::GCShower(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCShower::GCShower(void *ptr) {
    m_ptr = ptr;
}
std::string GCShower::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCShower::IsValid() {
    return (m_ptr != nullptr);
}
GCModelPointEntity GCShower::GetParent() const {
    GCModelPointEntity value(m_ptr);
    return value;
}
void GCShower::SetParent(GCModelPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCShower(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCShower>("CShower")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCShower::GetParent, &GCShower::SetParent)
        .addFunction("ToPtr", &GCShower::ToPtr)
        .addFunction("IsValid", &GCShower::IsValid)
        .endClass();
}