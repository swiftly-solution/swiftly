#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMorphData::GCMorphData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMorphData::GCMorphData(void *ptr) {
    m_ptr = ptr;
}
std::string GCMorphData::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CMorphData", "m_name").Get();
}
void GCMorphData::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CMorphData", "m_name", false, CUtlString(value.c_str()));
}
std::vector<GCMorphRectData> GCMorphData::GetMorphRectDatas() const {
    CUtlVector<GCMorphRectData>* vec = GetSchemaValue<CUtlVector<GCMorphRectData>*>(m_ptr, "CMorphData", "m_morphRectDatas"); std::vector<GCMorphRectData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMorphData::SetMorphRectDatas(std::vector<GCMorphRectData> value) {
    SetSchemaValueCUtlVector<GCMorphRectData>(m_ptr, "CMorphData", "m_morphRectDatas", false, value);
}
std::string GCMorphData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMorphData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMorphData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMorphData>("CMorphData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCMorphData::GetName, &GCMorphData::SetName)
        .addProperty("MorphRectDatas", &GCMorphData::GetMorphRectDatas, &GCMorphData::SetMorphRectDatas)
        .addFunction("ToPtr", &GCMorphData::ToPtr)
        .addFunction("IsValid", &GCMorphData::IsValid)
        .endClass();
}