#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAnimTagID::GAnimTagID(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAnimTagID::GAnimTagID(void *ptr) {
    m_ptr = ptr;
}
uint32_t GAnimTagID::GetId() const {
    return GetSchemaValue<uint32_t>(m_ptr, "AnimTagID", "m_id");
}
void GAnimTagID::SetId(uint32_t value) {
    SetSchemaValue(m_ptr, "AnimTagID", "m_id", false, value);
}
std::string GAnimTagID::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAnimTagID::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAnimTagID(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimTagID>("AnimTagID")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Id", &GAnimTagID::GetId, &GAnimTagID::SetId)
        .addFunction("ToPtr", &GAnimTagID::ToPtr)
        .addFunction("IsValid", &GAnimTagID::IsValid)
        .endClass();
}