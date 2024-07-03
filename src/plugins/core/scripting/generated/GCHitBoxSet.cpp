#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHitBoxSet::GCHitBoxSet(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHitBoxSet::GCHitBoxSet(void *ptr) {
    m_ptr = ptr;
}
std::string GCHitBoxSet::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CHitBoxSet", "m_name").Get();
}
void GCHitBoxSet::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CHitBoxSet", "m_name", false, CUtlString(value.c_str()));
}
uint32_t GCHitBoxSet::GetNameHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CHitBoxSet", "m_nNameHash");
}
void GCHitBoxSet::SetNameHash(uint32_t value) {
    SetSchemaValue(m_ptr, "CHitBoxSet", "m_nNameHash", false, value);
}
std::vector<GCHitBox> GCHitBoxSet::GetHitBoxes() const {
    CUtlVector<GCHitBox>* vec = GetSchemaValue<CUtlVector<GCHitBox>*>(m_ptr, "CHitBoxSet", "m_HitBoxes"); std::vector<GCHitBox> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCHitBoxSet::SetHitBoxes(std::vector<GCHitBox> value) {
    SetSchemaValueCUtlVector<GCHitBox>(m_ptr, "CHitBoxSet", "m_HitBoxes", false, value);
}
std::string GCHitBoxSet::GetSourceFilename() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CHitBoxSet", "m_SourceFilename").Get();
}
void GCHitBoxSet::SetSourceFilename(std::string value) {
    SetSchemaValue(m_ptr, "CHitBoxSet", "m_SourceFilename", false, CUtlString(value.c_str()));
}
std::string GCHitBoxSet::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHitBoxSet::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCHitBoxSet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHitBoxSet>("CHitBoxSet")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCHitBoxSet::GetName, &GCHitBoxSet::SetName)
        .addProperty("NameHash", &GCHitBoxSet::GetNameHash, &GCHitBoxSet::SetNameHash)
        .addProperty("HitBoxes", &GCHitBoxSet::GetHitBoxes, &GCHitBoxSet::SetHitBoxes)
        .addProperty("SourceFilename", &GCHitBoxSet::GetSourceFilename, &GCHitBoxSet::SetSourceFilename)
        .addFunction("ToPtr", &GCHitBoxSet::ToPtr)
        .addFunction("IsValid", &GCHitBoxSet::IsValid)
        .endClass();
}