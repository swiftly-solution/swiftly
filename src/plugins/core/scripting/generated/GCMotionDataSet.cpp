#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotionDataSet::GCMotionDataSet(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotionDataSet::GCMotionDataSet(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCMotionGraphGroup> GCMotionDataSet::GetGroups() const {
    CUtlVector<GCMotionGraphGroup>* vec = GetSchemaValue<CUtlVector<GCMotionGraphGroup>*>(m_ptr, "CMotionDataSet", "m_groups"); std::vector<GCMotionGraphGroup> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMotionDataSet::SetGroups(std::vector<GCMotionGraphGroup> value) {
    SetSchemaValueCUtlVector<GCMotionGraphGroup>(m_ptr, "CMotionDataSet", "m_groups", false, value);
}
int32_t GCMotionDataSet::GetDimensionCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMotionDataSet", "m_nDimensionCount");
}
void GCMotionDataSet::SetDimensionCount(int32_t value) {
    SetSchemaValue(m_ptr, "CMotionDataSet", "m_nDimensionCount", false, value);
}
std::string GCMotionDataSet::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotionDataSet::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMotionDataSet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionDataSet>("CMotionDataSet")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Groups", &GCMotionDataSet::GetGroups, &GCMotionDataSet::SetGroups)
        .addProperty("DimensionCount", &GCMotionDataSet::GetDimensionCount, &GCMotionDataSet::SetDimensionCount)
        .addFunction("ToPtr", &GCMotionDataSet::ToPtr)
        .addFunction("IsValid", &GCMotionDataSet::IsValid)
        .endClass();
}