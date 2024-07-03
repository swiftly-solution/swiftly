#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimParameterBase::GCAnimParameterBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimParameterBase::GCAnimParameterBase(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimParameterBase::GetComment() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAnimParameterBase", "m_sComment").Get();
}
void GCAnimParameterBase::SetComment(std::string value) {
    SetSchemaValue(m_ptr, "CAnimParameterBase", "m_sComment", false, CUtlString(value.c_str()));
}
std::string GCAnimParameterBase::GetGroup() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAnimParameterBase", "m_group").Get();
}
void GCAnimParameterBase::SetGroup(std::string value) {
    SetSchemaValue(m_ptr, "CAnimParameterBase", "m_group", false, CUtlString(value.c_str()));
}
GAnimParamID GCAnimParameterBase::GetId() const {
    GAnimParamID value(GetSchemaPtr(m_ptr, "CAnimParameterBase", "m_id"));
    return value;
}
void GCAnimParameterBase::SetId(GAnimParamID value) {
    SetSchemaValue(m_ptr, "CAnimParameterBase", "m_id", false, value);
}
std::string GCAnimParameterBase::GetComponentName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAnimParameterBase", "m_componentName").Get();
}
void GCAnimParameterBase::SetComponentName(std::string value) {
    SetSchemaValue(m_ptr, "CAnimParameterBase", "m_componentName", false, CUtlString(value.c_str()));
}
bool GCAnimParameterBase::GetNetworkingRequested() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimParameterBase", "m_bNetworkingRequested");
}
void GCAnimParameterBase::SetNetworkingRequested(bool value) {
    SetSchemaValue(m_ptr, "CAnimParameterBase", "m_bNetworkingRequested", false, value);
}
bool GCAnimParameterBase::GetIsReferenced() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimParameterBase", "m_bIsReferenced");
}
void GCAnimParameterBase::SetIsReferenced(bool value) {
    SetSchemaValue(m_ptr, "CAnimParameterBase", "m_bIsReferenced", false, value);
}
std::string GCAnimParameterBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimParameterBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimParameterBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimParameterBase>("CAnimParameterBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Comment", &GCAnimParameterBase::GetComment, &GCAnimParameterBase::SetComment)
        .addProperty("Group", &GCAnimParameterBase::GetGroup, &GCAnimParameterBase::SetGroup)
        .addProperty("Id", &GCAnimParameterBase::GetId, &GCAnimParameterBase::SetId)
        .addProperty("ComponentName", &GCAnimParameterBase::GetComponentName, &GCAnimParameterBase::SetComponentName)
        .addProperty("NetworkingRequested", &GCAnimParameterBase::GetNetworkingRequested, &GCAnimParameterBase::SetNetworkingRequested)
        .addProperty("IsReferenced", &GCAnimParameterBase::GetIsReferenced, &GCAnimParameterBase::SetIsReferenced)
        .addFunction("ToPtr", &GCAnimParameterBase::ToPtr)
        .addFunction("IsValid", &GCAnimParameterBase::IsValid)
        .endClass();
}