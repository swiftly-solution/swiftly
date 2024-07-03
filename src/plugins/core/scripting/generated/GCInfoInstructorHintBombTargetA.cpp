#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoInstructorHintBombTargetA::GCInfoInstructorHintBombTargetA(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoInstructorHintBombTargetA::GCInfoInstructorHintBombTargetA(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoInstructorHintBombTargetA::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoInstructorHintBombTargetA::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoInstructorHintBombTargetA::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoInstructorHintBombTargetA::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoInstructorHintBombTargetA(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoInstructorHintBombTargetA>("CInfoInstructorHintBombTargetA")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoInstructorHintBombTargetA::GetParent, &GCInfoInstructorHintBombTargetA::SetParent)
        .addFunction("ToPtr", &GCInfoInstructorHintBombTargetA::ToPtr)
        .addFunction("IsValid", &GCInfoInstructorHintBombTargetA::IsValid)
        .endClass();
}