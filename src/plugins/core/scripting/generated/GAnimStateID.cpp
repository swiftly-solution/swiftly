#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAnimStateID::GAnimStateID(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAnimStateID::GAnimStateID(void *ptr) {
    m_ptr = ptr;
}
uint32_t GAnimStateID::GetId() const {
    return GetSchemaValue<uint32_t>(m_ptr, "AnimStateID", "m_id");
}
void GAnimStateID::SetId(uint32_t value) {
    SetSchemaValue(m_ptr, "AnimStateID", "m_id", false, value);
}
std::string GAnimStateID::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAnimStateID::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAnimStateID(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimStateID>("AnimStateID")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Id", &GAnimStateID::GetId, &GAnimStateID::SetId)
        .addFunction("ToPtr", &GAnimStateID::ToPtr)
        .addFunction("IsValid", &GAnimStateID::IsValid)
        .endClass();
}