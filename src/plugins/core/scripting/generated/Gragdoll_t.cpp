#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gragdoll_t::Gragdoll_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gragdoll_t::Gragdoll_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<Gragdollelement_t> Gragdoll_t::GetList() const {
    CUtlVector<Gragdollelement_t>* vec = GetSchemaValue<CUtlVector<Gragdollelement_t>*>(m_ptr, "ragdoll_t", "list"); std::vector<Gragdollelement_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void Gragdoll_t::SetList(std::vector<Gragdollelement_t> value) {
    SetSchemaValueCUtlVector<Gragdollelement_t>(m_ptr, "ragdoll_t", "list", true, value);
}
std::vector<int32> Gragdoll_t::GetBoneIndex() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "ragdoll_t", "boneIndex"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void Gragdoll_t::SetBoneIndex(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "ragdoll_t", "boneIndex", true, value);
}
bool Gragdoll_t::GetAllowStretch() const {
    return GetSchemaValue<bool>(m_ptr, "ragdoll_t", "allowStretch");
}
void Gragdoll_t::SetAllowStretch(bool value) {
    SetSchemaValue(m_ptr, "ragdoll_t", "allowStretch", true, value);
}
bool Gragdoll_t::GetUnused() const {
    return GetSchemaValue<bool>(m_ptr, "ragdoll_t", "unused");
}
void Gragdoll_t::SetUnused(bool value) {
    SetSchemaValue(m_ptr, "ragdoll_t", "unused", true, value);
}
std::string Gragdoll_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gragdoll_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassragdoll_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gragdoll_t>("ragdoll_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("List", &Gragdoll_t::GetList, &Gragdoll_t::SetList)
        .addProperty("BoneIndex", &Gragdoll_t::GetBoneIndex, &Gragdoll_t::SetBoneIndex)
        .addProperty("AllowStretch", &Gragdoll_t::GetAllowStretch, &Gragdoll_t::SetAllowStretch)
        .addProperty("Unused", &Gragdoll_t::GetUnused, &Gragdoll_t::SetUnused)
        .addFunction("ToPtr", &Gragdoll_t::ToPtr)
        .addFunction("IsValid", &Gragdoll_t::IsValid)
        .endClass();
}