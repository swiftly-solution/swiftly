#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAnimNodeOutputID::GAnimNodeOutputID(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAnimNodeOutputID::GAnimNodeOutputID(void *ptr) {
    m_ptr = ptr;
}
uint32_t GAnimNodeOutputID::GetId() const {
    return GetSchemaValue<uint32_t>(m_ptr, "AnimNodeOutputID", "m_id");
}
void GAnimNodeOutputID::SetId(uint32_t value) {
    SetSchemaValue(m_ptr, "AnimNodeOutputID", "m_id", false, value);
}
std::string GAnimNodeOutputID::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAnimNodeOutputID::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAnimNodeOutputID(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimNodeOutputID>("AnimNodeOutputID")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Id", &GAnimNodeOutputID::GetId, &GAnimNodeOutputID::SetId)
        .addFunction("ToPtr", &GAnimNodeOutputID::ToPtr)
        .addFunction("IsValid", &GAnimNodeOutputID::IsValid)
        .endClass();
}