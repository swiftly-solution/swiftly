#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientSceneSystemThreadStateChange_t::GEventClientSceneSystemThreadStateChange_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientSceneSystemThreadStateChange_t::GEventClientSceneSystemThreadStateChange_t(void *ptr) {
    m_ptr = ptr;
}
bool GEventClientSceneSystemThreadStateChange_t::GetThreadsActive() const {
    return GetSchemaValue<bool>(m_ptr, "EventClientSceneSystemThreadStateChange_t", "m_bThreadsActive");
}
void GEventClientSceneSystemThreadStateChange_t::SetThreadsActive(bool value) {
    SetSchemaValue(m_ptr, "EventClientSceneSystemThreadStateChange_t", "m_bThreadsActive", true, value);
}
std::string GEventClientSceneSystemThreadStateChange_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientSceneSystemThreadStateChange_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventClientSceneSystemThreadStateChange_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientSceneSystemThreadStateChange_t>("EventClientSceneSystemThreadStateChange_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ThreadsActive", &GEventClientSceneSystemThreadStateChange_t::GetThreadsActive, &GEventClientSceneSystemThreadStateChange_t::SetThreadsActive)
        .addFunction("ToPtr", &GEventClientSceneSystemThreadStateChange_t::ToPtr)
        .addFunction("IsValid", &GEventClientSceneSystemThreadStateChange_t::IsValid)
        .endClass();
}