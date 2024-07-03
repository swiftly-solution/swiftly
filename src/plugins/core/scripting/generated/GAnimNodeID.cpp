#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAnimNodeID::GAnimNodeID(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAnimNodeID::GAnimNodeID(void *ptr) {
    m_ptr = ptr;
}
uint32_t GAnimNodeID::GetId() const {
    return GetSchemaValue<uint32_t>(m_ptr, "AnimNodeID", "m_id");
}
void GAnimNodeID::SetId(uint32_t value) {
    SetSchemaValue(m_ptr, "AnimNodeID", "m_id", false, value);
}
std::string GAnimNodeID::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAnimNodeID::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAnimNodeID(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimNodeID>("AnimNodeID")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Id", &GAnimNodeID::GetId, &GAnimNodeID::SetId)
        .addFunction("ToPtr", &GAnimNodeID::ToPtr)
        .addFunction("IsValid", &GAnimNodeID::IsValid)
        .endClass();
}