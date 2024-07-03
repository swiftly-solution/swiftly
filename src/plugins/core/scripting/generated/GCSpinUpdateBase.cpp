#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSpinUpdateBase::GCSpinUpdateBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSpinUpdateBase::GCSpinUpdateBase(void *ptr) {
    m_ptr = ptr;
}
std::string GCSpinUpdateBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSpinUpdateBase::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFunctionOperator GCSpinUpdateBase::GetParent() const {
    GCParticleFunctionOperator value(m_ptr);
    return value;
}
void GCSpinUpdateBase::SetParent(GCParticleFunctionOperator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSpinUpdateBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSpinUpdateBase>("CSpinUpdateBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSpinUpdateBase::GetParent, &GCSpinUpdateBase::SetParent)
        .addFunction("ToPtr", &GCSpinUpdateBase::ToPtr)
        .addFunction("IsValid", &GCSpinUpdateBase::IsValid)
        .endClass();
}