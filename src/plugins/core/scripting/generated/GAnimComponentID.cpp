#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAnimComponentID::GAnimComponentID(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAnimComponentID::GAnimComponentID(void *ptr) {
    m_ptr = ptr;
}
uint32_t GAnimComponentID::GetId() const {
    return GetSchemaValue<uint32_t>(m_ptr, "AnimComponentID", "m_id");
}
void GAnimComponentID::SetId(uint32_t value) {
    SetSchemaValue(m_ptr, "AnimComponentID", "m_id", false, value);
}
std::string GAnimComponentID::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAnimComponentID::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAnimComponentID(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimComponentID>("AnimComponentID")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Id", &GAnimComponentID::GetId, &GAnimComponentID::SetId)
        .addFunction("ToPtr", &GAnimComponentID::ToPtr)
        .addFunction("IsValid", &GAnimComponentID::IsValid)
        .endClass();
}