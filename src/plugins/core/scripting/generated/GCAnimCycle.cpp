#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimCycle::GCAnimCycle(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimCycle::GCAnimCycle(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimCycle::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimCycle::IsValid() {
    return (m_ptr != nullptr);
}
GCCycleBase GCAnimCycle::GetParent() const {
    GCCycleBase value(m_ptr);
    return value;
}
void GCAnimCycle::SetParent(GCCycleBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAnimCycle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimCycle>("CAnimCycle")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCAnimCycle::GetParent, &GCAnimCycle::SetParent)
        .addFunction("ToPtr", &GCAnimCycle::ToPtr)
        .addFunction("IsValid", &GCAnimCycle::IsValid)
        .endClass();
}