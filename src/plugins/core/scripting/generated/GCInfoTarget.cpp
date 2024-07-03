#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoTarget::GCInfoTarget(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoTarget::GCInfoTarget(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoTarget::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoTarget::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoTarget::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoTarget::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoTarget>("CInfoTarget")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoTarget::GetParent, &GCInfoTarget::SetParent)
        .addFunction("ToPtr", &GCInfoTarget::ToPtr)
        .addFunction("IsValid", &GCInfoTarget::IsValid)
        .endClass();
}