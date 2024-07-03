#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gsndopvarlatchdata_t::Gsndopvarlatchdata_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gsndopvarlatchdata_t::Gsndopvarlatchdata_t(void *ptr) {
    m_ptr = ptr;
}
std::string Gsndopvarlatchdata_t::GetStack() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "sndopvarlatchdata_t", "m_iszStack").String();
}
void Gsndopvarlatchdata_t::SetStack(std::string value) {
    SetSchemaValue(m_ptr, "sndopvarlatchdata_t", "m_iszStack", true, CUtlSymbolLarge(value.c_str()));
}
std::string Gsndopvarlatchdata_t::GetOperator() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "sndopvarlatchdata_t", "m_iszOperator").String();
}
void Gsndopvarlatchdata_t::SetOperator(std::string value) {
    SetSchemaValue(m_ptr, "sndopvarlatchdata_t", "m_iszOperator", true, CUtlSymbolLarge(value.c_str()));
}
std::string Gsndopvarlatchdata_t::GetOpvar() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "sndopvarlatchdata_t", "m_iszOpvar").String();
}
void Gsndopvarlatchdata_t::SetOpvar(std::string value) {
    SetSchemaValue(m_ptr, "sndopvarlatchdata_t", "m_iszOpvar", true, CUtlSymbolLarge(value.c_str()));
}
float Gsndopvarlatchdata_t::GetVal() const {
    return GetSchemaValue<float>(m_ptr, "sndopvarlatchdata_t", "m_flVal");
}
void Gsndopvarlatchdata_t::SetVal(float value) {
    SetSchemaValue(m_ptr, "sndopvarlatchdata_t", "m_flVal", true, value);
}
Vector Gsndopvarlatchdata_t::GetPos() const {
    return GetSchemaValue<Vector>(m_ptr, "sndopvarlatchdata_t", "m_vPos");
}
void Gsndopvarlatchdata_t::SetPos(Vector value) {
    SetSchemaValue(m_ptr, "sndopvarlatchdata_t", "m_vPos", true, value);
}
std::string Gsndopvarlatchdata_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gsndopvarlatchdata_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClasssndopvarlatchdata_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gsndopvarlatchdata_t>("sndopvarlatchdata_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Stack", &Gsndopvarlatchdata_t::GetStack, &Gsndopvarlatchdata_t::SetStack)
        .addProperty("Operator", &Gsndopvarlatchdata_t::GetOperator, &Gsndopvarlatchdata_t::SetOperator)
        .addProperty("Opvar", &Gsndopvarlatchdata_t::GetOpvar, &Gsndopvarlatchdata_t::SetOpvar)
        .addProperty("Val", &Gsndopvarlatchdata_t::GetVal, &Gsndopvarlatchdata_t::SetVal)
        .addProperty("Pos", &Gsndopvarlatchdata_t::GetPos, &Gsndopvarlatchdata_t::SetPos)
        .addFunction("ToPtr", &Gsndopvarlatchdata_t::ToPtr)
        .addFunction("IsValid", &Gsndopvarlatchdata_t::IsValid)
        .endClass();
}