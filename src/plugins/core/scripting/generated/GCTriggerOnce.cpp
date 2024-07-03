#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerOnce::GCTriggerOnce(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerOnce::GCTriggerOnce(void *ptr) {
    m_ptr = ptr;
}
std::string GCTriggerOnce::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerOnce::IsValid() {
    return (m_ptr != nullptr);
}
GCTriggerMultiple GCTriggerOnce::GetParent() const {
    GCTriggerMultiple value(m_ptr);
    return value;
}
void GCTriggerOnce::SetParent(GCTriggerMultiple value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerOnce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerOnce>("CTriggerOnce")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTriggerOnce::GetParent, &GCTriggerOnce::SetParent)
        .addFunction("ToPtr", &GCTriggerOnce::ToPtr)
        .addFunction("IsValid", &GCTriggerOnce::IsValid)
        .endClass();
}