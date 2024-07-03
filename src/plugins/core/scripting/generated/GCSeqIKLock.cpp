#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqIKLock::GCSeqIKLock(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqIKLock::GCSeqIKLock(void *ptr) {
    m_ptr = ptr;
}
float GCSeqIKLock::GetPosWeight() const {
    return GetSchemaValue<float>(m_ptr, "CSeqIKLock", "m_flPosWeight");
}
void GCSeqIKLock::SetPosWeight(float value) {
    SetSchemaValue(m_ptr, "CSeqIKLock", "m_flPosWeight", false, value);
}
float GCSeqIKLock::GetAngleWeight() const {
    return GetSchemaValue<float>(m_ptr, "CSeqIKLock", "m_flAngleWeight");
}
void GCSeqIKLock::SetAngleWeight(float value) {
    SetSchemaValue(m_ptr, "CSeqIKLock", "m_flAngleWeight", false, value);
}
int16_t GCSeqIKLock::GetLocalBone() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqIKLock", "m_nLocalBone");
}
void GCSeqIKLock::SetLocalBone(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqIKLock", "m_nLocalBone", false, value);
}
bool GCSeqIKLock::GetBonesOrientedAlongPositiveX() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqIKLock", "m_bBonesOrientedAlongPositiveX");
}
void GCSeqIKLock::SetBonesOrientedAlongPositiveX(bool value) {
    SetSchemaValue(m_ptr, "CSeqIKLock", "m_bBonesOrientedAlongPositiveX", false, value);
}
std::string GCSeqIKLock::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqIKLock::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqIKLock(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqIKLock>("CSeqIKLock")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PosWeight", &GCSeqIKLock::GetPosWeight, &GCSeqIKLock::SetPosWeight)
        .addProperty("AngleWeight", &GCSeqIKLock::GetAngleWeight, &GCSeqIKLock::SetAngleWeight)
        .addProperty("LocalBone", &GCSeqIKLock::GetLocalBone, &GCSeqIKLock::SetLocalBone)
        .addProperty("BonesOrientedAlongPositiveX", &GCSeqIKLock::GetBonesOrientedAlongPositiveX, &GCSeqIKLock::SetBonesOrientedAlongPositiveX)
        .addFunction("ToPtr", &GCSeqIKLock::ToPtr)
        .addFunction("IsValid", &GCSeqIKLock::IsValid)
        .endClass();
}