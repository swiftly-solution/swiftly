#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTransitionUpdateData::GCTransitionUpdateData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTransitionUpdateData::GCTransitionUpdateData(void *ptr) {
    m_ptr = ptr;
}
uint8_t GCTransitionUpdateData::GetSrcStateIndex() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CTransitionUpdateData", "m_srcStateIndex");
}
void GCTransitionUpdateData::SetSrcStateIndex(uint8_t value) {
    SetSchemaValue(m_ptr, "CTransitionUpdateData", "m_srcStateIndex", false, value);
}
uint8_t GCTransitionUpdateData::GetDestStateIndex() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CTransitionUpdateData", "m_destStateIndex");
}
void GCTransitionUpdateData::SetDestStateIndex(uint8_t value) {
    SetSchemaValue(m_ptr, "CTransitionUpdateData", "m_destStateIndex", false, value);
}
std::string GCTransitionUpdateData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTransitionUpdateData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCTransitionUpdateData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTransitionUpdateData>("CTransitionUpdateData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SrcStateIndex", &GCTransitionUpdateData::GetSrcStateIndex, &GCTransitionUpdateData::SetSrcStateIndex)
        .addProperty("DestStateIndex", &GCTransitionUpdateData::GetDestStateIndex, &GCTransitionUpdateData::SetDestStateIndex)
        .addFunction("ToPtr", &GCTransitionUpdateData::ToPtr)
        .addFunction("IsValid", &GCTransitionUpdateData::IsValid)
        .endClass();
}