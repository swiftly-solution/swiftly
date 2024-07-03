#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotionSearchDB::GCMotionSearchDB(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotionSearchDB::GCMotionSearchDB(void *ptr) {
    m_ptr = ptr;
}
GCMotionSearchNode GCMotionSearchDB::GetRootNode() const {
    GCMotionSearchNode value(GetSchemaPtr(m_ptr, "CMotionSearchDB", "m_rootNode"));
    return value;
}
void GCMotionSearchDB::SetRootNode(GCMotionSearchNode value) {
    SetSchemaValue(m_ptr, "CMotionSearchDB", "m_rootNode", false, value);
}
GCProductQuantizer GCMotionSearchDB::GetResidualQuantizer() const {
    GCProductQuantizer value(GetSchemaPtr(m_ptr, "CMotionSearchDB", "m_residualQuantizer"));
    return value;
}
void GCMotionSearchDB::SetResidualQuantizer(GCProductQuantizer value) {
    SetSchemaValue(m_ptr, "CMotionSearchDB", "m_residualQuantizer", false, value);
}
std::vector<GMotionDBIndex> GCMotionSearchDB::GetCodeIndices() const {
    CUtlVector<GMotionDBIndex>* vec = GetSchemaValue<CUtlVector<GMotionDBIndex>*>(m_ptr, "CMotionSearchDB", "m_codeIndices"); std::vector<GMotionDBIndex> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMotionSearchDB::SetCodeIndices(std::vector<GMotionDBIndex> value) {
    SetSchemaValueCUtlVector<GMotionDBIndex>(m_ptr, "CMotionSearchDB", "m_codeIndices", false, value);
}
std::string GCMotionSearchDB::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotionSearchDB::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMotionSearchDB(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionSearchDB>("CMotionSearchDB")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RootNode", &GCMotionSearchDB::GetRootNode, &GCMotionSearchDB::SetRootNode)
        .addProperty("ResidualQuantizer", &GCMotionSearchDB::GetResidualQuantizer, &GCMotionSearchDB::SetResidualQuantizer)
        .addProperty("CodeIndices", &GCMotionSearchDB::GetCodeIndices, &GCMotionSearchDB::SetCodeIndices)
        .addFunction("ToPtr", &GCMotionSearchDB::ToPtr)
        .addFunction("IsValid", &GCMotionSearchDB::IsValid)
        .endClass();
}