#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimFrameSegment::GCAnimFrameSegment(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimFrameSegment::GCAnimFrameSegment(void *ptr) {
    m_ptr = ptr;
}
int32_t GCAnimFrameSegment::GetUniqueFrameIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimFrameSegment", "m_nUniqueFrameIndex");
}
void GCAnimFrameSegment::SetUniqueFrameIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimFrameSegment", "m_nUniqueFrameIndex", false, value);
}
uint32_t GCAnimFrameSegment::GetLocalElementMasks() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CAnimFrameSegment", "m_nLocalElementMasks");
}
void GCAnimFrameSegment::SetLocalElementMasks(uint32_t value) {
    SetSchemaValue(m_ptr, "CAnimFrameSegment", "m_nLocalElementMasks", false, value);
}
int32_t GCAnimFrameSegment::GetLocalChannel() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimFrameSegment", "m_nLocalChannel");
}
void GCAnimFrameSegment::SetLocalChannel(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimFrameSegment", "m_nLocalChannel", false, value);
}
std::string GCAnimFrameSegment::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimFrameSegment::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimFrameSegment(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimFrameSegment>("CAnimFrameSegment")
        .addConstructor<void (*)(std::string)>()
        .addProperty("UniqueFrameIndex", &GCAnimFrameSegment::GetUniqueFrameIndex, &GCAnimFrameSegment::SetUniqueFrameIndex)
        .addProperty("LocalElementMasks", &GCAnimFrameSegment::GetLocalElementMasks, &GCAnimFrameSegment::SetLocalElementMasks)
        .addProperty("LocalChannel", &GCAnimFrameSegment::GetLocalChannel, &GCAnimFrameSegment::SetLocalChannel)
        .addFunction("ToPtr", &GCAnimFrameSegment::ToPtr)
        .addFunction("IsValid", &GCAnimFrameSegment::IsValid)
        .endClass();
}