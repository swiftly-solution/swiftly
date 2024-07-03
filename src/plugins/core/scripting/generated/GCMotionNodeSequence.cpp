#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotionNodeSequence::GCMotionNodeSequence(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotionNodeSequence::GCMotionNodeSequence(void *ptr) {
    m_ptr = ptr;
}
std::vector<GTagSpan_t> GCMotionNodeSequence::GetTags() const {
    CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "CMotionNodeSequence", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMotionNodeSequence::SetTags(std::vector<GTagSpan_t> value) {
    SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "CMotionNodeSequence", "m_tags", false, value);
}
float GCMotionNodeSequence::GetPlaybackSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CMotionNodeSequence", "m_flPlaybackSpeed");
}
void GCMotionNodeSequence::SetPlaybackSpeed(float value) {
    SetSchemaValue(m_ptr, "CMotionNodeSequence", "m_flPlaybackSpeed", false, value);
}
std::string GCMotionNodeSequence::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotionNodeSequence::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionNode GCMotionNodeSequence::GetParent() const {
    GCMotionNode value(m_ptr);
    return value;
}
void GCMotionNodeSequence::SetParent(GCMotionNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMotionNodeSequence(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionNodeSequence>("CMotionNodeSequence")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Tags", &GCMotionNodeSequence::GetTags, &GCMotionNodeSequence::SetTags)
        .addProperty("PlaybackSpeed", &GCMotionNodeSequence::GetPlaybackSpeed, &GCMotionNodeSequence::SetPlaybackSpeed)
        .addProperty("Parent", &GCMotionNodeSequence::GetParent, &GCMotionNodeSequence::SetParent)
        .addFunction("ToPtr", &GCMotionNodeSequence::ToPtr)
        .addFunction("IsValid", &GCMotionNodeSequence::IsValid)
        .endClass();
}