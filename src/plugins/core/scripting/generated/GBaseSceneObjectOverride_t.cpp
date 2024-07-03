#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GBaseSceneObjectOverride_t::GBaseSceneObjectOverride_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GBaseSceneObjectOverride_t::GBaseSceneObjectOverride_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GBaseSceneObjectOverride_t::GetSceneObjectIndex() const {
    return GetSchemaValue<uint32_t>(m_ptr, "BaseSceneObjectOverride_t", "m_nSceneObjectIndex");
}
void GBaseSceneObjectOverride_t::SetSceneObjectIndex(uint32_t value) {
    SetSchemaValue(m_ptr, "BaseSceneObjectOverride_t", "m_nSceneObjectIndex", true, value);
}
std::string GBaseSceneObjectOverride_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GBaseSceneObjectOverride_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassBaseSceneObjectOverride_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GBaseSceneObjectOverride_t>("BaseSceneObjectOverride_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SceneObjectIndex", &GBaseSceneObjectOverride_t::GetSceneObjectIndex, &GBaseSceneObjectOverride_t::SetSceneObjectIndex)
        .addFunction("ToPtr", &GBaseSceneObjectOverride_t::ToPtr)
        .addFunction("IsValid", &GBaseSceneObjectOverride_t::IsValid)
        .endClass();
}