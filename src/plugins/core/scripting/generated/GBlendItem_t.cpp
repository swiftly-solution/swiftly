#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GBlendItem_t::GBlendItem_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GBlendItem_t::GBlendItem_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GTagSpan_t> GBlendItem_t::GetTags() const {
    CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "BlendItem_t", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GBlendItem_t::SetTags(std::vector<GTagSpan_t> value) {
    SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "BlendItem_t", "m_tags", true, value);
}
GCAnimUpdateNodeRef GBlendItem_t::GetChild() const {
    GCAnimUpdateNodeRef value(GetSchemaPtr(m_ptr, "BlendItem_t", "m_pChild"));
    return value;
}
void GBlendItem_t::SetChild(GCAnimUpdateNodeRef value) {
    SetSchemaValue(m_ptr, "BlendItem_t", "m_pChild", true, value);
}
Vector2D GBlendItem_t::GetPos() const {
    return GetSchemaValue<Vector2D>(m_ptr, "BlendItem_t", "m_vPos");
}
void GBlendItem_t::SetPos(Vector2D value) {
    SetSchemaValue(m_ptr, "BlendItem_t", "m_vPos", true, value);
}
float GBlendItem_t::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "BlendItem_t", "m_flDuration");
}
void GBlendItem_t::SetDuration(float value) {
    SetSchemaValue(m_ptr, "BlendItem_t", "m_flDuration", true, value);
}
bool GBlendItem_t::GetUseCustomDuration() const {
    return GetSchemaValue<bool>(m_ptr, "BlendItem_t", "m_bUseCustomDuration");
}
void GBlendItem_t::SetUseCustomDuration(bool value) {
    SetSchemaValue(m_ptr, "BlendItem_t", "m_bUseCustomDuration", true, value);
}
std::string GBlendItem_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GBlendItem_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassBlendItem_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GBlendItem_t>("BlendItem_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Tags", &GBlendItem_t::GetTags, &GBlendItem_t::SetTags)
        .addProperty("Child", &GBlendItem_t::GetChild, &GBlendItem_t::SetChild)
        .addProperty("Pos", &GBlendItem_t::GetPos, &GBlendItem_t::SetPos)
        .addProperty("Duration", &GBlendItem_t::GetDuration, &GBlendItem_t::SetDuration)
        .addProperty("UseCustomDuration", &GBlendItem_t::GetUseCustomDuration, &GBlendItem_t::SetUseCustomDuration)
        .addFunction("ToPtr", &GBlendItem_t::ToPtr)
        .addFunction("IsValid", &GBlendItem_t::IsValid)
        .endClass();
}