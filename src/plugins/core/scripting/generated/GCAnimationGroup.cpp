#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimationGroup::GCAnimationGroup(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimationGroup::GCAnimationGroup(void *ptr) {
    m_ptr = ptr;
}
uint32_t GCAnimationGroup::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CAnimationGroup", "m_nFlags");
}
void GCAnimationGroup::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "CAnimationGroup", "m_nFlags", false, value);
}
CBufferString GCAnimationGroup::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimationGroup", "m_name");
}
void GCAnimationGroup::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimationGroup", "m_name", false, value);
}
GCAnimKeyData GCAnimationGroup::GetDecodeKey() const {
    GCAnimKeyData value(GetSchemaPtr(m_ptr, "CAnimationGroup", "m_decodeKey"));
    return value;
}
void GCAnimationGroup::SetDecodeKey(GCAnimKeyData value) {
    SetSchemaValue(m_ptr, "CAnimationGroup", "m_decodeKey", false, value);
}
std::vector<CBufferString> GCAnimationGroup::GetScripts() const {
    CUtlVector<CBufferString>* vec = GetSchemaValue<CUtlVector<CBufferString>*>(m_ptr, "CAnimationGroup", "m_szScripts"); std::vector<CBufferString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimationGroup::SetScripts(std::vector<CBufferString> value) {
    SetSchemaValueCUtlVector<CBufferString>(m_ptr, "CAnimationGroup", "m_szScripts", false, value);
}
std::string GCAnimationGroup::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimationGroup::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimationGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGroup>("CAnimationGroup")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Flags", &GCAnimationGroup::GetFlags, &GCAnimationGroup::SetFlags)
        .addProperty("Name", &GCAnimationGroup::GetName, &GCAnimationGroup::SetName)
        .addProperty("DecodeKey", &GCAnimationGroup::GetDecodeKey, &GCAnimationGroup::SetDecodeKey)
        .addProperty("Scripts", &GCAnimationGroup::GetScripts, &GCAnimationGroup::SetScripts)
        .addFunction("ToPtr", &GCAnimationGroup::ToPtr)
        .addFunction("IsValid", &GCAnimationGroup::IsValid)
        .endClass();
}