#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWorld::GCWorld(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWorld::GCWorld(void *ptr) {
    m_ptr = ptr;
}
std::string GCWorld::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWorld::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCWorld::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCWorld::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWorld(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWorld>("CWorld")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWorld::GetParent, &GCWorld::SetParent)
        .addFunction("ToPtr", &GCWorld::ToPtr)
        .addFunction("IsValid", &GCWorld::IsValid)
        .endClass();
}