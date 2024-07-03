#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathAnimMotorUpdater::GCPathAnimMotorUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathAnimMotorUpdater::GCPathAnimMotorUpdater(void *ptr) {
    m_ptr = ptr;
}
std::string GCPathAnimMotorUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathAnimMotorUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCPathAnimMotorUpdaterBase GCPathAnimMotorUpdater::GetParent() const {
    GCPathAnimMotorUpdaterBase value(m_ptr);
    return value;
}
void GCPathAnimMotorUpdater::SetParent(GCPathAnimMotorUpdaterBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPathAnimMotorUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathAnimMotorUpdater>("CPathAnimMotorUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPathAnimMotorUpdater::GetParent, &GCPathAnimMotorUpdater::SetParent)
        .addFunction("ToPtr", &GCPathAnimMotorUpdater::ToPtr)
        .addFunction("IsValid", &GCPathAnimMotorUpdater::IsValid)
        .endClass();
}