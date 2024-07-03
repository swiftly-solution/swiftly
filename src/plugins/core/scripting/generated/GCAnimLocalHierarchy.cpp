#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimLocalHierarchy::GCAnimLocalHierarchy(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimLocalHierarchy::GCAnimLocalHierarchy(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimLocalHierarchy::GetBone() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimLocalHierarchy", "m_sBone");
}
void GCAnimLocalHierarchy::SetBone(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimLocalHierarchy", "m_sBone", false, value);
}
CBufferString GCAnimLocalHierarchy::GetNewParent() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimLocalHierarchy", "m_sNewParent");
}
void GCAnimLocalHierarchy::SetNewParent(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimLocalHierarchy", "m_sNewParent", false, value);
}
int32_t GCAnimLocalHierarchy::GetStartFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimLocalHierarchy", "m_nStartFrame");
}
void GCAnimLocalHierarchy::SetStartFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimLocalHierarchy", "m_nStartFrame", false, value);
}
int32_t GCAnimLocalHierarchy::GetPeakFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimLocalHierarchy", "m_nPeakFrame");
}
void GCAnimLocalHierarchy::SetPeakFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimLocalHierarchy", "m_nPeakFrame", false, value);
}
int32_t GCAnimLocalHierarchy::GetTailFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimLocalHierarchy", "m_nTailFrame");
}
void GCAnimLocalHierarchy::SetTailFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimLocalHierarchy", "m_nTailFrame", false, value);
}
int32_t GCAnimLocalHierarchy::GetEndFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimLocalHierarchy", "m_nEndFrame");
}
void GCAnimLocalHierarchy::SetEndFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimLocalHierarchy", "m_nEndFrame", false, value);
}
std::string GCAnimLocalHierarchy::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimLocalHierarchy::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimLocalHierarchy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimLocalHierarchy>("CAnimLocalHierarchy")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Bone", &GCAnimLocalHierarchy::GetBone, &GCAnimLocalHierarchy::SetBone)
        .addProperty("NewParent", &GCAnimLocalHierarchy::GetNewParent, &GCAnimLocalHierarchy::SetNewParent)
        .addProperty("StartFrame", &GCAnimLocalHierarchy::GetStartFrame, &GCAnimLocalHierarchy::SetStartFrame)
        .addProperty("PeakFrame", &GCAnimLocalHierarchy::GetPeakFrame, &GCAnimLocalHierarchy::SetPeakFrame)
        .addProperty("TailFrame", &GCAnimLocalHierarchy::GetTailFrame, &GCAnimLocalHierarchy::SetTailFrame)
        .addProperty("EndFrame", &GCAnimLocalHierarchy::GetEndFrame, &GCAnimLocalHierarchy::SetEndFrame)
        .addFunction("ToPtr", &GCAnimLocalHierarchy::ToPtr)
        .addFunction("IsValid", &GCAnimLocalHierarchy::IsValid)
        .endClass();
}