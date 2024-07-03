#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAnimationDecodeDebugDump_t::GAnimationDecodeDebugDump_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAnimationDecodeDebugDump_t::GAnimationDecodeDebugDump_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GAnimationDecodeDebugDump_t::GetProcessingType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "AnimationDecodeDebugDump_t", "m_processingType");
}
void GAnimationDecodeDebugDump_t::SetProcessingType(uint64_t value) {
    SetSchemaValue(m_ptr, "AnimationDecodeDebugDump_t", "m_processingType", true, value);
}
std::vector<GAnimationDecodeDebugDumpElement_t> GAnimationDecodeDebugDump_t::GetElems() const {
    CUtlVector<GAnimationDecodeDebugDumpElement_t>* vec = GetSchemaValue<CUtlVector<GAnimationDecodeDebugDumpElement_t>*>(m_ptr, "AnimationDecodeDebugDump_t", "m_elems"); std::vector<GAnimationDecodeDebugDumpElement_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAnimationDecodeDebugDump_t::SetElems(std::vector<GAnimationDecodeDebugDumpElement_t> value) {
    SetSchemaValueCUtlVector<GAnimationDecodeDebugDumpElement_t>(m_ptr, "AnimationDecodeDebugDump_t", "m_elems", true, value);
}
std::string GAnimationDecodeDebugDump_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAnimationDecodeDebugDump_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAnimationDecodeDebugDump_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimationDecodeDebugDump_t>("AnimationDecodeDebugDump_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ProcessingType", &GAnimationDecodeDebugDump_t::GetProcessingType, &GAnimationDecodeDebugDump_t::SetProcessingType)
        .addProperty("Elems", &GAnimationDecodeDebugDump_t::GetElems, &GAnimationDecodeDebugDump_t::SetElems)
        .addFunction("ToPtr", &GAnimationDecodeDebugDump_t::ToPtr)
        .addFunction("IsValid", &GAnimationDecodeDebugDump_t::IsValid)
        .endClass();
}