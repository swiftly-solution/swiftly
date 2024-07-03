#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootMotion::GCFootMotion(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootMotion::GCFootMotion(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCFootStride> GCFootMotion::GetStrides() const {
    CUtlVector<GCFootStride>* vec = GetSchemaValue<CUtlVector<GCFootStride>*>(m_ptr, "CFootMotion", "m_strides"); std::vector<GCFootStride> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFootMotion::SetStrides(std::vector<GCFootStride> value) {
    SetSchemaValueCUtlVector<GCFootStride>(m_ptr, "CFootMotion", "m_strides", false, value);
}
std::string GCFootMotion::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFootMotion", "m_name").Get();
}
void GCFootMotion::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CFootMotion", "m_name", false, CUtlString(value.c_str()));
}
bool GCFootMotion::GetAdditive() const {
    return GetSchemaValue<bool>(m_ptr, "CFootMotion", "m_bAdditive");
}
void GCFootMotion::SetAdditive(bool value) {
    SetSchemaValue(m_ptr, "CFootMotion", "m_bAdditive", false, value);
}
std::string GCFootMotion::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootMotion::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFootMotion(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootMotion>("CFootMotion")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Strides", &GCFootMotion::GetStrides, &GCFootMotion::SetStrides)
        .addProperty("Name", &GCFootMotion::GetName, &GCFootMotion::SetName)
        .addProperty("Additive", &GCFootMotion::GetAdditive, &GCFootMotion::SetAdditive)
        .addFunction("ToPtr", &GCFootMotion::ToPtr)
        .addFunction("IsValid", &GCFootMotion::IsValid)
        .endClass();
}