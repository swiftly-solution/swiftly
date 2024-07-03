#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootCycle::GCFootCycle(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootCycle::GCFootCycle(void *ptr) {
    m_ptr = ptr;
}
std::string GCFootCycle::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootCycle::IsValid() {
    return (m_ptr != nullptr);
}
GCCycleBase GCFootCycle::GetParent() const {
    GCCycleBase value(m_ptr);
    return value;
}
void GCFootCycle::SetParent(GCCycleBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFootCycle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootCycle>("CFootCycle")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCFootCycle::GetParent, &GCFootCycle::SetParent)
        .addFunction("ToPtr", &GCFootCycle::ToPtr)
        .addFunction("IsValid", &GCFootCycle::IsValid)
        .endClass();
}