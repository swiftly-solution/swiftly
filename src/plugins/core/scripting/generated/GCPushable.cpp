#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPushable::GCPushable(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPushable::GCPushable(void *ptr) {
    m_ptr = ptr;
}
std::string GCPushable::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPushable::IsValid() {
    return (m_ptr != nullptr);
}
GCBreakable GCPushable::GetParent() const {
    GCBreakable value(m_ptr);
    return value;
}
void GCPushable::SetParent(GCBreakable value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPushable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPushable>("CPushable")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPushable::GetParent, &GCPushable::SetParent)
        .addFunction("ToPtr", &GCPushable::ToPtr)
        .addFunction("IsValid", &GCPushable::IsValid)
        .endClass();
}