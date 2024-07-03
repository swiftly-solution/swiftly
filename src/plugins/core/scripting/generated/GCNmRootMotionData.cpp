#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmRootMotionData::GCNmRootMotionData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmRootMotionData::GCNmRootMotionData(void *ptr) {
    m_ptr = ptr;
}
int32_t GCNmRootMotionData::GetNumFrames() const {
    return GetSchemaValue<int32_t>(m_ptr, "CNmRootMotionData", "m_nNumFrames");
}
void GCNmRootMotionData::SetNumFrames(int32_t value) {
    SetSchemaValue(m_ptr, "CNmRootMotionData", "m_nNumFrames", false, value);
}
float GCNmRootMotionData::GetAverageLinearVelocity() const {
    return GetSchemaValue<float>(m_ptr, "CNmRootMotionData", "m_flAverageLinearVelocity");
}
void GCNmRootMotionData::SetAverageLinearVelocity(float value) {
    SetSchemaValue(m_ptr, "CNmRootMotionData", "m_flAverageLinearVelocity", false, value);
}
float GCNmRootMotionData::GetAverageAngularVelocityRadians() const {
    return GetSchemaValue<float>(m_ptr, "CNmRootMotionData", "m_flAverageAngularVelocityRadians");
}
void GCNmRootMotionData::SetAverageAngularVelocityRadians(float value) {
    SetSchemaValue(m_ptr, "CNmRootMotionData", "m_flAverageAngularVelocityRadians", false, value);
}
std::string GCNmRootMotionData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmRootMotionData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmRootMotionData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmRootMotionData>("CNmRootMotionData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NumFrames", &GCNmRootMotionData::GetNumFrames, &GCNmRootMotionData::SetNumFrames)
        .addProperty("AverageLinearVelocity", &GCNmRootMotionData::GetAverageLinearVelocity, &GCNmRootMotionData::SetAverageLinearVelocity)
        .addProperty("AverageAngularVelocityRadians", &GCNmRootMotionData::GetAverageAngularVelocityRadians, &GCNmRootMotionData::SetAverageAngularVelocityRadians)
        .addFunction("ToPtr", &GCNmRootMotionData::ToPtr)
        .addFunction("IsValid", &GCNmRootMotionData::IsValid)
        .endClass();
}