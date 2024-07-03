#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimationGraphVisualizerPrimitiveBase::GCAnimationGraphVisualizerPrimitiveBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimationGraphVisualizerPrimitiveBase::GCAnimationGraphVisualizerPrimitiveBase(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCAnimationGraphVisualizerPrimitiveBase::GetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_Type");
}
void GCAnimationGraphVisualizerPrimitiveBase::SetType(uint64_t value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_Type", false, value);
}
std::vector<GAnimNodeID> GCAnimationGraphVisualizerPrimitiveBase::GetOwningAnimNodePaths() const {
    GAnimNodeID* outValue = GetSchemaValue<GAnimNodeID*>(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_OwningAnimNodePaths"); std::vector<GAnimNodeID> ret; for(int i = 0; i < 11; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCAnimationGraphVisualizerPrimitiveBase::SetOwningAnimNodePaths(std::vector<GAnimNodeID> value) {
    GAnimNodeID* outValue = GetSchemaValue<GAnimNodeID*>(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_OwningAnimNodePaths"); for(int i = 0; i < 11; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_OwningAnimNodePaths", false, outValue);
}
int32_t GCAnimationGraphVisualizerPrimitiveBase::GetOwningAnimNodePathCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_nOwningAnimNodePathCount");
}
void GCAnimationGraphVisualizerPrimitiveBase::SetOwningAnimNodePathCount(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPrimitiveBase", "m_nOwningAnimNodePathCount", false, value);
}
std::string GCAnimationGraphVisualizerPrimitiveBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimationGraphVisualizerPrimitiveBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimationGraphVisualizerPrimitiveBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGraphVisualizerPrimitiveBase>("CAnimationGraphVisualizerPrimitiveBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Type", &GCAnimationGraphVisualizerPrimitiveBase::GetType, &GCAnimationGraphVisualizerPrimitiveBase::SetType)
        .addProperty("OwningAnimNodePaths", &GCAnimationGraphVisualizerPrimitiveBase::GetOwningAnimNodePaths, &GCAnimationGraphVisualizerPrimitiveBase::SetOwningAnimNodePaths)
        .addProperty("OwningAnimNodePathCount", &GCAnimationGraphVisualizerPrimitiveBase::GetOwningAnimNodePathCount, &GCAnimationGraphVisualizerPrimitiveBase::SetOwningAnimNodePathCount)
        .addFunction("ToPtr", &GCAnimationGraphVisualizerPrimitiveBase::ToPtr)
        .addFunction("IsValid", &GCAnimationGraphVisualizerPrimitiveBase::IsValid)
        .endClass();
}