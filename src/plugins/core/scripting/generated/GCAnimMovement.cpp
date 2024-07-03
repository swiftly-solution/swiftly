#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimMovement::GCAnimMovement(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimMovement::GCAnimMovement(void *ptr) {
    m_ptr = ptr;
}
int32_t GCAnimMovement::GetEndframe() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimMovement", "endframe");
}
void GCAnimMovement::SetEndframe(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimMovement", "endframe", false, value);
}
int32_t GCAnimMovement::GetMotionflags() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimMovement", "motionflags");
}
void GCAnimMovement::SetMotionflags(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimMovement", "motionflags", false, value);
}
float GCAnimMovement::Get0() const {
    return GetSchemaValue<float>(m_ptr, "CAnimMovement", "v0");
}
void GCAnimMovement::Set0(float value) {
    SetSchemaValue(m_ptr, "CAnimMovement", "v0", false, value);
}
float GCAnimMovement::Get1() const {
    return GetSchemaValue<float>(m_ptr, "CAnimMovement", "v1");
}
void GCAnimMovement::Set1(float value) {
    SetSchemaValue(m_ptr, "CAnimMovement", "v1", false, value);
}
float GCAnimMovement::GetAngle() const {
    return GetSchemaValue<float>(m_ptr, "CAnimMovement", "angle");
}
void GCAnimMovement::SetAngle(float value) {
    SetSchemaValue(m_ptr, "CAnimMovement", "angle", false, value);
}
Vector GCAnimMovement::GetVector() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimMovement", "vector");
}
void GCAnimMovement::SetVector(Vector value) {
    SetSchemaValue(m_ptr, "CAnimMovement", "vector", false, value);
}
Vector GCAnimMovement::GetPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimMovement", "position");
}
void GCAnimMovement::SetPosition(Vector value) {
    SetSchemaValue(m_ptr, "CAnimMovement", "position", false, value);
}
std::string GCAnimMovement::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimMovement::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimMovement(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimMovement>("CAnimMovement")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Endframe", &GCAnimMovement::GetEndframe, &GCAnimMovement::SetEndframe)
        .addProperty("Motionflags", &GCAnimMovement::GetMotionflags, &GCAnimMovement::SetMotionflags)
        .addProperty("0", &GCAnimMovement::Get0, &GCAnimMovement::Set0)
        .addProperty("1", &GCAnimMovement::Get1, &GCAnimMovement::Set1)
        .addProperty("Angle", &GCAnimMovement::GetAngle, &GCAnimMovement::SetAngle)
        .addProperty("Vector", &GCAnimMovement::GetVector, &GCAnimMovement::SetVector)
        .addProperty("Position", &GCAnimMovement::GetPosition, &GCAnimMovement::SetPosition)
        .addFunction("ToPtr", &GCAnimMovement::ToPtr)
        .addFunction("IsValid", &GCAnimMovement::IsValid)
        .endClass();
}