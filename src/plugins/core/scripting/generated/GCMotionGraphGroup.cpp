#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotionGraphGroup::GCMotionGraphGroup(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotionGraphGroup::GCMotionGraphGroup(void *ptr) {
    m_ptr = ptr;
}
GCMotionSearchDB GCMotionGraphGroup::GetSearchDB() const {
    GCMotionSearchDB value(GetSchemaPtr(m_ptr, "CMotionGraphGroup", "m_searchDB"));
    return value;
}
void GCMotionGraphGroup::SetSearchDB(GCMotionSearchDB value) {
    SetSchemaValue(m_ptr, "CMotionGraphGroup", "m_searchDB", false, value);
}
std::vector<GCMotionGraphConfig> GCMotionGraphGroup::GetMotionGraphConfigs() const {
    CUtlVector<GCMotionGraphConfig>* vec = GetSchemaValue<CUtlVector<GCMotionGraphConfig>*>(m_ptr, "CMotionGraphGroup", "m_motionGraphConfigs"); std::vector<GCMotionGraphConfig> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMotionGraphGroup::SetMotionGraphConfigs(std::vector<GCMotionGraphConfig> value) {
    SetSchemaValueCUtlVector<GCMotionGraphConfig>(m_ptr, "CMotionGraphGroup", "m_motionGraphConfigs", false, value);
}
std::vector<int32> GCMotionGraphGroup::GetSampleToConfig() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CMotionGraphGroup", "m_sampleToConfig"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMotionGraphGroup::SetSampleToConfig(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CMotionGraphGroup", "m_sampleToConfig", false, value);
}
GAnimScriptHandle GCMotionGraphGroup::GetIsActiveScript() const {
    GAnimScriptHandle value(GetSchemaPtr(m_ptr, "CMotionGraphGroup", "m_hIsActiveScript"));
    return value;
}
void GCMotionGraphGroup::SetIsActiveScript(GAnimScriptHandle value) {
    SetSchemaValue(m_ptr, "CMotionGraphGroup", "m_hIsActiveScript", false, value);
}
std::string GCMotionGraphGroup::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotionGraphGroup::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMotionGraphGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionGraphGroup>("CMotionGraphGroup")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SearchDB", &GCMotionGraphGroup::GetSearchDB, &GCMotionGraphGroup::SetSearchDB)
        .addProperty("MotionGraphConfigs", &GCMotionGraphGroup::GetMotionGraphConfigs, &GCMotionGraphGroup::SetMotionGraphConfigs)
        .addProperty("SampleToConfig", &GCMotionGraphGroup::GetSampleToConfig, &GCMotionGraphGroup::SetSampleToConfig)
        .addProperty("IsActiveScript", &GCMotionGraphGroup::GetIsActiveScript, &GCMotionGraphGroup::SetIsActiveScript)
        .addFunction("ToPtr", &GCMotionGraphGroup::ToPtr)
        .addFunction("IsValid", &GCMotionGraphGroup::IsValid)
        .endClass();
}