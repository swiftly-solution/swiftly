#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRegionSVM::GCRegionSVM(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRegionSVM::GCRegionSVM(void *ptr) {
    m_ptr = ptr;
}
std::vector<GRnPlane_t> GCRegionSVM::GetPlanes() const {
    CUtlVector<GRnPlane_t>* vec = GetSchemaValue<CUtlVector<GRnPlane_t>*>(m_ptr, "CRegionSVM", "m_Planes"); std::vector<GRnPlane_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRegionSVM::SetPlanes(std::vector<GRnPlane_t> value) {
    SetSchemaValueCUtlVector<GRnPlane_t>(m_ptr, "CRegionSVM", "m_Planes", false, value);
}
std::vector<uint32> GCRegionSVM::GetNodes() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CRegionSVM", "m_Nodes"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRegionSVM::SetNodes(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "CRegionSVM", "m_Nodes", false, value);
}
std::string GCRegionSVM::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRegionSVM::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCRegionSVM(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRegionSVM>("CRegionSVM")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Planes", &GCRegionSVM::GetPlanes, &GCRegionSVM::SetPlanes)
        .addProperty("Nodes", &GCRegionSVM::GetNodes, &GCRegionSVM::SetNodes)
        .addFunction("ToPtr", &GCRegionSVM::ToPtr)
        .addFunction("IsValid", &GCRegionSVM::IsValid)
        .endClass();
}