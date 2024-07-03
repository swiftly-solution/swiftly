#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimUser::GCAnimUser(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimUser::GCAnimUser(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimUser::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimUser", "m_name");
}
void GCAnimUser::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimUser", "m_name", false, value);
}
int32_t GCAnimUser::GetType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimUser", "m_nType");
}
void GCAnimUser::SetType(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimUser", "m_nType", false, value);
}
std::string GCAnimUser::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimUser::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimUser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimUser>("CAnimUser")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimUser::GetName, &GCAnimUser::SetName)
        .addProperty("Type", &GCAnimUser::GetType, &GCAnimUser::SetType)
        .addFunction("ToPtr", &GCAnimUser::ToPtr)
        .addFunction("IsValid", &GCAnimUser::IsValid)
        .endClass();
}