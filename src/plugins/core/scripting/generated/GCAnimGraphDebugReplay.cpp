#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimGraphDebugReplay::GCAnimGraphDebugReplay(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimGraphDebugReplay::GCAnimGraphDebugReplay(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimGraphDebugReplay::GetAnimGraphFileName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAnimGraphDebugReplay", "m_animGraphFileName").Get();
}
void GCAnimGraphDebugReplay::SetAnimGraphFileName(std::string value) {
    SetSchemaValue(m_ptr, "CAnimGraphDebugReplay", "m_animGraphFileName", false, CUtlString(value.c_str()));
}
int32_t GCAnimGraphDebugReplay::GetStartIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimGraphDebugReplay", "m_startIndex");
}
void GCAnimGraphDebugReplay::SetStartIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimGraphDebugReplay", "m_startIndex", false, value);
}
int32_t GCAnimGraphDebugReplay::GetWriteIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimGraphDebugReplay", "m_writeIndex");
}
void GCAnimGraphDebugReplay::SetWriteIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimGraphDebugReplay", "m_writeIndex", false, value);
}
int32_t GCAnimGraphDebugReplay::GetFrameCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimGraphDebugReplay", "m_frameCount");
}
void GCAnimGraphDebugReplay::SetFrameCount(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimGraphDebugReplay", "m_frameCount", false, value);
}
std::string GCAnimGraphDebugReplay::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimGraphDebugReplay::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimGraphDebugReplay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphDebugReplay>("CAnimGraphDebugReplay")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AnimGraphFileName", &GCAnimGraphDebugReplay::GetAnimGraphFileName, &GCAnimGraphDebugReplay::SetAnimGraphFileName)
        .addProperty("StartIndex", &GCAnimGraphDebugReplay::GetStartIndex, &GCAnimGraphDebugReplay::SetStartIndex)
        .addProperty("WriteIndex", &GCAnimGraphDebugReplay::GetWriteIndex, &GCAnimGraphDebugReplay::SetWriteIndex)
        .addProperty("FrameCount", &GCAnimGraphDebugReplay::GetFrameCount, &GCAnimGraphDebugReplay::SetFrameCount)
        .addFunction("ToPtr", &GCAnimGraphDebugReplay::ToPtr)
        .addFunction("IsValid", &GCAnimGraphDebugReplay::IsValid)
        .endClass();
}