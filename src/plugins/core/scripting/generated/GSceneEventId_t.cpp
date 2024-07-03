#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSceneEventId_t::GSceneEventId_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSceneEventId_t::GSceneEventId_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GSceneEventId_t::GetValue() const {
    return GetSchemaValue<uint32_t>(m_ptr, "SceneEventId_t", "m_Value");
}
void GSceneEventId_t::SetValue(uint32_t value) {
    SetSchemaValue(m_ptr, "SceneEventId_t", "m_Value", true, value);
}
std::string GSceneEventId_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSceneEventId_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSceneEventId_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSceneEventId_t>("SceneEventId_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GSceneEventId_t::GetValue, &GSceneEventId_t::SetValue)
        .addFunction("ToPtr", &GSceneEventId_t::ToPtr)
        .addFunction("IsValid", &GSceneEventId_t::IsValid)
        .endClass();
}