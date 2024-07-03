#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootTrajectory::GCFootTrajectory(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootTrajectory::GCFootTrajectory(void *ptr) {
    m_ptr = ptr;
}
Vector GCFootTrajectory::GetOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "CFootTrajectory", "m_vOffset");
}
void GCFootTrajectory::SetOffset(Vector value) {
    SetSchemaValue(m_ptr, "CFootTrajectory", "m_vOffset", false, value);
}
float GCFootTrajectory::GetRotationOffset() const {
    return GetSchemaValue<float>(m_ptr, "CFootTrajectory", "m_flRotationOffset");
}
void GCFootTrajectory::SetRotationOffset(float value) {
    SetSchemaValue(m_ptr, "CFootTrajectory", "m_flRotationOffset", false, value);
}
float GCFootTrajectory::GetProgression() const {
    return GetSchemaValue<float>(m_ptr, "CFootTrajectory", "m_flProgression");
}
void GCFootTrajectory::SetProgression(float value) {
    SetSchemaValue(m_ptr, "CFootTrajectory", "m_flProgression", false, value);
}
std::string GCFootTrajectory::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootTrajectory::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFootTrajectory(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootTrajectory>("CFootTrajectory")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Offset", &GCFootTrajectory::GetOffset, &GCFootTrajectory::SetOffset)
        .addProperty("RotationOffset", &GCFootTrajectory::GetRotationOffset, &GCFootTrajectory::SetRotationOffset)
        .addProperty("Progression", &GCFootTrajectory::GetProgression, &GCFootTrajectory::SetProgression)
        .addFunction("ToPtr", &GCFootTrajectory::ToPtr)
        .addFunction("IsValid", &GCFootTrajectory::IsValid)
        .endClass();
}