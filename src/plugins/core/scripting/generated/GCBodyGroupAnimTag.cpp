#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBodyGroupAnimTag::GCBodyGroupAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBodyGroupAnimTag::GCBodyGroupAnimTag(void *ptr) {
    m_ptr = ptr;
}
int32_t GCBodyGroupAnimTag::GetPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBodyGroupAnimTag", "m_nPriority");
}
void GCBodyGroupAnimTag::SetPriority(int32_t value) {
    SetSchemaValue(m_ptr, "CBodyGroupAnimTag", "m_nPriority", false, value);
}
std::vector<GCBodyGroupSetting> GCBodyGroupAnimTag::GetBodyGroupSettings() const {
    CUtlVector<GCBodyGroupSetting>* vec = GetSchemaValue<CUtlVector<GCBodyGroupSetting>*>(m_ptr, "CBodyGroupAnimTag", "m_bodyGroupSettings"); std::vector<GCBodyGroupSetting> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBodyGroupAnimTag::SetBodyGroupSettings(std::vector<GCBodyGroupSetting> value) {
    SetSchemaValueCUtlVector<GCBodyGroupSetting>(m_ptr, "CBodyGroupAnimTag", "m_bodyGroupSettings", false, value);
}
std::string GCBodyGroupAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBodyGroupAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimTagBase GCBodyGroupAnimTag::GetParent() const {
    GCAnimTagBase value(m_ptr);
    return value;
}
void GCBodyGroupAnimTag::SetParent(GCAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBodyGroupAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyGroupAnimTag>("CBodyGroupAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Priority", &GCBodyGroupAnimTag::GetPriority, &GCBodyGroupAnimTag::SetPriority)
        .addProperty("BodyGroupSettings", &GCBodyGroupAnimTag::GetBodyGroupSettings, &GCBodyGroupAnimTag::SetBodyGroupSettings)
        .addProperty("Parent", &GCBodyGroupAnimTag::GetParent, &GCBodyGroupAnimTag::SetParent)
        .addFunction("ToPtr", &GCBodyGroupAnimTag::ToPtr)
        .addFunction("IsValid", &GCBodyGroupAnimTag::IsValid)
        .endClass();
}