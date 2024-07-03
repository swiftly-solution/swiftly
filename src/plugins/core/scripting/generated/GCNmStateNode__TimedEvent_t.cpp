#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmStateNode__TimedEvent_t::GCNmStateNode__TimedEvent_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmStateNode__TimedEvent_t::GCNmStateNode__TimedEvent_t(void *ptr) {
    m_ptr = ptr;
}
float GCNmStateNode__TimedEvent_t::GetTimeValue() const {
    return GetSchemaValue<float>(m_ptr, "CNmStateNode__TimedEvent_t", "m_timeValue");
}
void GCNmStateNode__TimedEvent_t::SetTimeValue(float value) {
    SetSchemaValue(m_ptr, "CNmStateNode__TimedEvent_t", "m_timeValue", true, value);
}
std::string GCNmStateNode__TimedEvent_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmStateNode__TimedEvent_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmStateNode__TimedEvent_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmStateNode__TimedEvent_t>("CNmStateNode__TimedEvent_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TimeValue", &GCNmStateNode__TimedEvent_t::GetTimeValue, &GCNmStateNode__TimedEvent_t::SetTimeValue)
        .addFunction("ToPtr", &GCNmStateNode__TimedEvent_t::ToPtr)
        .addFunction("IsValid", &GCNmStateNode__TimedEvent_t::IsValid)
        .endClass();
}