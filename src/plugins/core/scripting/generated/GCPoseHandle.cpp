#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPoseHandle::GCPoseHandle(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPoseHandle::GCPoseHandle(void *ptr) {
    m_ptr = ptr;
}
uint16_t GCPoseHandle::GetIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CPoseHandle", "m_nIndex");
}
void GCPoseHandle::SetIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "CPoseHandle", "m_nIndex", false, value);
}
uint64_t GCPoseHandle::GetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPoseHandle", "m_eType");
}
void GCPoseHandle::SetType(uint64_t value) {
    SetSchemaValue(m_ptr, "CPoseHandle", "m_eType", false, value);
}
std::string GCPoseHandle::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPoseHandle::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCPoseHandle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPoseHandle>("CPoseHandle")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Index", &GCPoseHandle::GetIndex, &GCPoseHandle::SetIndex)
        .addProperty("Type", &GCPoseHandle::GetType, &GCPoseHandle::SetType)
        .addFunction("ToPtr", &GCPoseHandle::ToPtr)
        .addFunction("IsValid", &GCPoseHandle::IsValid)
        .endClass();
}