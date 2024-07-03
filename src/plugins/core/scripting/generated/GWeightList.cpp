#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GWeightList::GWeightList(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GWeightList::GWeightList(void *ptr) {
    m_ptr = ptr;
}
std::string GWeightList::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "WeightList", "m_name").Get();
}
void GWeightList::SetName(std::string value) {
    SetSchemaValue(m_ptr, "WeightList", "m_name", false, CUtlString(value.c_str()));
}
std::vector<float32> GWeightList::GetWeights() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "WeightList", "m_weights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWeightList::SetWeights(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "WeightList", "m_weights", false, value);
}
std::string GWeightList::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GWeightList::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassWeightList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWeightList>("WeightList")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GWeightList::GetName, &GWeightList::SetName)
        .addProperty("Weights", &GWeightList::GetWeights, &GWeightList::SetWeights)
        .addFunction("ToPtr", &GWeightList::ToPtr)
        .addFunction("IsValid", &GWeightList::IsValid)
        .endClass();
}