#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimParamHandle::GCAnimParamHandle(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimParamHandle::GCAnimParamHandle(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCAnimParamHandle::GetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CAnimParamHandle", "m_type");
}
void GCAnimParamHandle::SetType(uint64_t value) {
    SetSchemaValue(m_ptr, "CAnimParamHandle", "m_type", false, value);
}
uint8_t GCAnimParamHandle::GetIndex() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CAnimParamHandle", "m_index");
}
void GCAnimParamHandle::SetIndex(uint8_t value) {
    SetSchemaValue(m_ptr, "CAnimParamHandle", "m_index", false, value);
}
std::string GCAnimParamHandle::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimParamHandle::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimParamHandle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimParamHandle>("CAnimParamHandle")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Type", &GCAnimParamHandle::GetType, &GCAnimParamHandle::SetType)
        .addProperty("Index", &GCAnimParamHandle::GetIndex, &GCAnimParamHandle::SetIndex)
        .addFunction("ToPtr", &GCAnimParamHandle::ToPtr)
        .addFunction("IsValid", &GCAnimParamHandle::IsValid)
        .endClass();
}