#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoPlayerCounterterrorist::GCInfoPlayerCounterterrorist(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoPlayerCounterterrorist::GCInfoPlayerCounterterrorist(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoPlayerCounterterrorist::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoPlayerCounterterrorist::IsValid() {
    return (m_ptr != nullptr);
}
GSpawnPoint GCInfoPlayerCounterterrorist::GetParent() const {
    GSpawnPoint value(m_ptr);
    return value;
}
void GCInfoPlayerCounterterrorist::SetParent(GSpawnPoint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoPlayerCounterterrorist(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoPlayerCounterterrorist>("CInfoPlayerCounterterrorist")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoPlayerCounterterrorist::GetParent, &GCInfoPlayerCounterterrorist::SetParent)
        .addFunction("ToPtr", &GCInfoPlayerCounterterrorist::ToPtr)
        .addFunction("IsValid", &GCInfoPlayerCounterterrorist::IsValid)
        .endClass();
}