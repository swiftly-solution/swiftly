#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEntityBlocker::GCEntityBlocker(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEntityBlocker::GCEntityBlocker(void *ptr) {
    m_ptr = ptr;
}
std::string GCEntityBlocker::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEntityBlocker::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCEntityBlocker::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCEntityBlocker::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEntityBlocker(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityBlocker>("CEntityBlocker")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCEntityBlocker::GetParent, &GCEntityBlocker::SetParent)
        .addFunction("ToPtr", &GCEntityBlocker::ToPtr)
        .addFunction("IsValid", &GCEntityBlocker::IsValid)
        .endClass();
}