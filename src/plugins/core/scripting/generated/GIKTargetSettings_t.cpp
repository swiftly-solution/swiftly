#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIKTargetSettings_t::GIKTargetSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIKTargetSettings_t::GIKTargetSettings_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GIKTargetSettings_t::GetTargetSource() const {
    return GetSchemaValue<uint64_t>(m_ptr, "IKTargetSettings_t", "m_TargetSource");
}
void GIKTargetSettings_t::SetTargetSource(uint64_t value) {
    SetSchemaValue(m_ptr, "IKTargetSettings_t", "m_TargetSource", true, value);
}
GIKBoneNameAndIndex_t GIKTargetSettings_t::GetBone() const {
    GIKBoneNameAndIndex_t value(GetSchemaPtr(m_ptr, "IKTargetSettings_t", "m_Bone"));
    return value;
}
void GIKTargetSettings_t::SetBone(GIKBoneNameAndIndex_t value) {
    SetSchemaValue(m_ptr, "IKTargetSettings_t", "m_Bone", true, value);
}
GAnimParamID GIKTargetSettings_t::GetAnimgraphParameterNamePosition() const {
    GAnimParamID value(GetSchemaPtr(m_ptr, "IKTargetSettings_t", "m_AnimgraphParameterNamePosition"));
    return value;
}
void GIKTargetSettings_t::SetAnimgraphParameterNamePosition(GAnimParamID value) {
    SetSchemaValue(m_ptr, "IKTargetSettings_t", "m_AnimgraphParameterNamePosition", true, value);
}
GAnimParamID GIKTargetSettings_t::GetAnimgraphParameterNameOrientation() const {
    GAnimParamID value(GetSchemaPtr(m_ptr, "IKTargetSettings_t", "m_AnimgraphParameterNameOrientation"));
    return value;
}
void GIKTargetSettings_t::SetAnimgraphParameterNameOrientation(GAnimParamID value) {
    SetSchemaValue(m_ptr, "IKTargetSettings_t", "m_AnimgraphParameterNameOrientation", true, value);
}
uint64_t GIKTargetSettings_t::GetTargetCoordSystem() const {
    return GetSchemaValue<uint64_t>(m_ptr, "IKTargetSettings_t", "m_TargetCoordSystem");
}
void GIKTargetSettings_t::SetTargetCoordSystem(uint64_t value) {
    SetSchemaValue(m_ptr, "IKTargetSettings_t", "m_TargetCoordSystem", true, value);
}
std::string GIKTargetSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIKTargetSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIKTargetSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIKTargetSettings_t>("IKTargetSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetSource", &GIKTargetSettings_t::GetTargetSource, &GIKTargetSettings_t::SetTargetSource)
        .addProperty("Bone", &GIKTargetSettings_t::GetBone, &GIKTargetSettings_t::SetBone)
        .addProperty("AnimgraphParameterNamePosition", &GIKTargetSettings_t::GetAnimgraphParameterNamePosition, &GIKTargetSettings_t::SetAnimgraphParameterNamePosition)
        .addProperty("AnimgraphParameterNameOrientation", &GIKTargetSettings_t::GetAnimgraphParameterNameOrientation, &GIKTargetSettings_t::SetAnimgraphParameterNameOrientation)
        .addProperty("TargetCoordSystem", &GIKTargetSettings_t::GetTargetCoordSystem, &GIKTargetSettings_t::SetTargetCoordSystem)
        .addFunction("ToPtr", &GIKTargetSettings_t::ToPtr)
        .addFunction("IsValid", &GIKTargetSettings_t::IsValid)
        .endClass();
}