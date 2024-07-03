#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmBoneMask::GCNmBoneMask(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmBoneMask::GCNmBoneMask(void *ptr) {
    m_ptr = ptr;
}
GCNmBoneMask GCNmBoneMask::GetWeightInfo() const {
    GCNmBoneMask value(GetSchemaPtr(m_ptr, "CNmBoneMask", "m_weightInfo"));
    return value;
}
void GCNmBoneMask::SetWeightInfo(GCNmBoneMask value) {
    SetSchemaValue(m_ptr, "CNmBoneMask", "m_weightInfo", false, value);
}
std::vector<float32> GCNmBoneMask::GetWeights() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CNmBoneMask", "m_weights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCNmBoneMask::SetWeights(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CNmBoneMask", "m_weights", false, value);
}
std::string GCNmBoneMask::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmBoneMask::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmBoneMask(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmBoneMask>("CNmBoneMask")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WeightInfo", &GCNmBoneMask::GetWeightInfo, &GCNmBoneMask::SetWeightInfo)
        .addProperty("Weights", &GCNmBoneMask::GetWeights, &GCNmBoneMask::SetWeights)
        .addFunction("ToPtr", &GCNmBoneMask::ToPtr)
        .addFunction("IsValid", &GCNmBoneMask::IsValid)
        .endClass();
}