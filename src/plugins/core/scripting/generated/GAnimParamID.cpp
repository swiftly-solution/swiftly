#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAnimParamID::GAnimParamID(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAnimParamID::GAnimParamID(void *ptr) {
    m_ptr = ptr;
}
uint32_t GAnimParamID::GetId() const {
    return GetSchemaValue<uint32_t>(m_ptr, "AnimParamID", "m_id");
}
void GAnimParamID::SetId(uint32_t value) {
    SetSchemaValue(m_ptr, "AnimParamID", "m_id", false, value);
}
std::string GAnimParamID::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAnimParamID::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAnimParamID(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimParamID>("AnimParamID")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Id", &GAnimParamID::GetId, &GAnimParamID::SetId)
        .addFunction("ToPtr", &GAnimParamID::ToPtr)
        .addFunction("IsValid", &GAnimParamID::IsValid)
        .endClass();
}