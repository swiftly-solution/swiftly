#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCachedPose::GCCachedPose(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCachedPose::GCCachedPose(void *ptr) {
    m_ptr = ptr;
}
std::vector<float32> GCCachedPose::GetMorphWeights() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CCachedPose", "m_morphWeights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCachedPose::SetMorphWeights(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CCachedPose", "m_morphWeights", false, value);
}
float GCCachedPose::GetCycle() const {
    return GetSchemaValue<float>(m_ptr, "CCachedPose", "m_flCycle");
}
void GCCachedPose::SetCycle(float value) {
    SetSchemaValue(m_ptr, "CCachedPose", "m_flCycle", false, value);
}
std::string GCCachedPose::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCachedPose::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCachedPose(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCachedPose>("CCachedPose")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MorphWeights", &GCCachedPose::GetMorphWeights, &GCCachedPose::SetMorphWeights)
        .addProperty("Cycle", &GCCachedPose::GetCycle, &GCCachedPose::SetCycle)
        .addFunction("ToPtr", &GCCachedPose::ToPtr)
        .addFunction("IsValid", &GCCachedPose::IsValid)
        .endClass();
}