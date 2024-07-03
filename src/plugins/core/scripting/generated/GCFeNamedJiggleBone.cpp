#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFeNamedJiggleBone::GCFeNamedJiggleBone(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFeNamedJiggleBone::GCFeNamedJiggleBone(void *ptr) {
    m_ptr = ptr;
}
std::string GCFeNamedJiggleBone::GetStrParentBone() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFeNamedJiggleBone", "m_strParentBone").Get();
}
void GCFeNamedJiggleBone::SetStrParentBone(std::string value) {
    SetSchemaValue(m_ptr, "CFeNamedJiggleBone", "m_strParentBone", false, CUtlString(value.c_str()));
}
uint32_t GCFeNamedJiggleBone::GetJiggleParent() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CFeNamedJiggleBone", "m_nJiggleParent");
}
void GCFeNamedJiggleBone::SetJiggleParent(uint32_t value) {
    SetSchemaValue(m_ptr, "CFeNamedJiggleBone", "m_nJiggleParent", false, value);
}
GCFeJiggleBone GCFeNamedJiggleBone::GetJiggleBone() const {
    GCFeJiggleBone value(GetSchemaPtr(m_ptr, "CFeNamedJiggleBone", "m_jiggleBone"));
    return value;
}
void GCFeNamedJiggleBone::SetJiggleBone(GCFeJiggleBone value) {
    SetSchemaValue(m_ptr, "CFeNamedJiggleBone", "m_jiggleBone", false, value);
}
std::string GCFeNamedJiggleBone::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFeNamedJiggleBone::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFeNamedJiggleBone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFeNamedJiggleBone>("CFeNamedJiggleBone")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StrParentBone", &GCFeNamedJiggleBone::GetStrParentBone, &GCFeNamedJiggleBone::SetStrParentBone)
        .addProperty("JiggleParent", &GCFeNamedJiggleBone::GetJiggleParent, &GCFeNamedJiggleBone::SetJiggleParent)
        .addProperty("JiggleBone", &GCFeNamedJiggleBone::GetJiggleBone, &GCFeNamedJiggleBone::SetJiggleBone)
        .addFunction("ToPtr", &GCFeNamedJiggleBone::ToPtr)
        .addFunction("IsValid", &GCFeNamedJiggleBone::IsValid)
        .endClass();
}