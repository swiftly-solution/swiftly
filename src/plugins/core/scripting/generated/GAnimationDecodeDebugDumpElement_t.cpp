#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAnimationDecodeDebugDumpElement_t::GAnimationDecodeDebugDumpElement_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAnimationDecodeDebugDumpElement_t::GAnimationDecodeDebugDumpElement_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GAnimationDecodeDebugDumpElement_t::GetEntityIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_nEntityIndex");
}
void GAnimationDecodeDebugDumpElement_t::SetEntityIndex(int32_t value) {
    SetSchemaValue(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_nEntityIndex", true, value);
}
std::string GAnimationDecodeDebugDumpElement_t::GetModelName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_modelName").Get();
}
void GAnimationDecodeDebugDumpElement_t::SetModelName(std::string value) {
    SetSchemaValue(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_modelName", true, CUtlString(value.c_str()));
}
std::vector<CUtlString> GAnimationDecodeDebugDumpElement_t::GetPoseParams() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_poseParams"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAnimationDecodeDebugDumpElement_t::SetPoseParams(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_poseParams", true, value);
}
std::vector<CUtlString> GAnimationDecodeDebugDumpElement_t::GetDecodeOps() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_decodeOps"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAnimationDecodeDebugDumpElement_t::SetDecodeOps(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_decodeOps", true, value);
}
std::vector<CUtlString> GAnimationDecodeDebugDumpElement_t::GetInternalOps() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_internalOps"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAnimationDecodeDebugDumpElement_t::SetInternalOps(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_internalOps", true, value);
}
std::vector<CUtlString> GAnimationDecodeDebugDumpElement_t::GetDecodedAnims() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_decodedAnims"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAnimationDecodeDebugDumpElement_t::SetDecodedAnims(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_decodedAnims", true, value);
}
std::string GAnimationDecodeDebugDumpElement_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAnimationDecodeDebugDumpElement_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAnimationDecodeDebugDumpElement_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimationDecodeDebugDumpElement_t>("AnimationDecodeDebugDumpElement_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EntityIndex", &GAnimationDecodeDebugDumpElement_t::GetEntityIndex, &GAnimationDecodeDebugDumpElement_t::SetEntityIndex)
        .addProperty("ModelName", &GAnimationDecodeDebugDumpElement_t::GetModelName, &GAnimationDecodeDebugDumpElement_t::SetModelName)
        .addProperty("PoseParams", &GAnimationDecodeDebugDumpElement_t::GetPoseParams, &GAnimationDecodeDebugDumpElement_t::SetPoseParams)
        .addProperty("DecodeOps", &GAnimationDecodeDebugDumpElement_t::GetDecodeOps, &GAnimationDecodeDebugDumpElement_t::SetDecodeOps)
        .addProperty("InternalOps", &GAnimationDecodeDebugDumpElement_t::GetInternalOps, &GAnimationDecodeDebugDumpElement_t::SetInternalOps)
        .addProperty("DecodedAnims", &GAnimationDecodeDebugDumpElement_t::GetDecodedAnims, &GAnimationDecodeDebugDumpElement_t::SetDecodedAnims)
        .addFunction("ToPtr", &GAnimationDecodeDebugDumpElement_t::ToPtr)
        .addFunction("IsValid", &GAnimationDecodeDebugDumpElement_t::IsValid)
        .endClass();
}