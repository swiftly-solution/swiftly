#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoInstructorHintBombTargetB::GCInfoInstructorHintBombTargetB(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoInstructorHintBombTargetB::GCInfoInstructorHintBombTargetB(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoInstructorHintBombTargetB::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoInstructorHintBombTargetB::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoInstructorHintBombTargetB::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoInstructorHintBombTargetB::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoInstructorHintBombTargetB(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoInstructorHintBombTargetB>("CInfoInstructorHintBombTargetB")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoInstructorHintBombTargetB::GetParent, &GCInfoInstructorHintBombTargetB::SetParent)
        .addFunction("ToPtr", &GCInfoInstructorHintBombTargetB::ToPtr)
        .addFunction("IsValid", &GCInfoInstructorHintBombTargetB::IsValid)
        .endClass();
}