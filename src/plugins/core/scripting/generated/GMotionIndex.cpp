#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMotionIndex::GMotionIndex(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMotionIndex::GMotionIndex(void *ptr) {
    m_ptr = ptr;
}
uint16_t GMotionIndex::GetGroup() const {
    return GetSchemaValue<uint16_t>(m_ptr, "MotionIndex", "m_nGroup");
}
void GMotionIndex::SetGroup(uint16_t value) {
    SetSchemaValue(m_ptr, "MotionIndex", "m_nGroup", false, value);
}
uint16_t GMotionIndex::GetMotion() const {
    return GetSchemaValue<uint16_t>(m_ptr, "MotionIndex", "m_nMotion");
}
void GMotionIndex::SetMotion(uint16_t value) {
    SetSchemaValue(m_ptr, "MotionIndex", "m_nMotion", false, value);
}
std::string GMotionIndex::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMotionIndex::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassMotionIndex(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMotionIndex>("MotionIndex")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Group", &GMotionIndex::GetGroup, &GMotionIndex::SetGroup)
        .addProperty("Motion", &GMotionIndex::GetMotion, &GMotionIndex::SetMotion)
        .addFunction("ToPtr", &GMotionIndex::ToPtr)
        .addFunction("IsValid", &GMotionIndex::IsValid)
        .endClass();
}