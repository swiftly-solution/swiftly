#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCycleBase::GCCycleBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCycleBase::GCCycleBase(void *ptr) {
    m_ptr = ptr;
}
float GCCycleBase::GetCycle() const {
    return GetSchemaValue<float>(m_ptr, "CCycleBase", "m_flCycle");
}
void GCCycleBase::SetCycle(float value) {
    SetSchemaValue(m_ptr, "CCycleBase", "m_flCycle", false, value);
}
std::string GCCycleBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCycleBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCycleBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCycleBase>("CCycleBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Cycle", &GCCycleBase::GetCycle, &GCCycleBase::SetCycle)
        .addFunction("ToPtr", &GCCycleBase::ToPtr)
        .addFunction("IsValid", &GCCycleBase::IsValid)
        .endClass();
}