#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAnimScriptHandle::GAnimScriptHandle(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAnimScriptHandle::GAnimScriptHandle(void *ptr) {
    m_ptr = ptr;
}
uint32_t GAnimScriptHandle::GetId() const {
    return GetSchemaValue<uint32_t>(m_ptr, "AnimScriptHandle", "m_id");
}
void GAnimScriptHandle::SetId(uint32_t value) {
    SetSchemaValue(m_ptr, "AnimScriptHandle", "m_id", false, value);
}
std::string GAnimScriptHandle::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAnimScriptHandle::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAnimScriptHandle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimScriptHandle>("AnimScriptHandle")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Id", &GAnimScriptHandle::GetId, &GAnimScriptHandle::SetId)
        .addFunction("ToPtr", &GAnimScriptHandle::ToPtr)
        .addFunction("IsValid", &GAnimScriptHandle::IsValid)
        .endClass();
}