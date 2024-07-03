#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gthinkfunc_t::Gthinkfunc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gthinkfunc_t::Gthinkfunc_t(void *ptr) {
    m_ptr = ptr;
}
CUtlStringToken Gthinkfunc_t::GetContext() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "thinkfunc_t", "m_nContext");
}
void Gthinkfunc_t::SetContext(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "thinkfunc_t", "m_nContext", true, value);
}
int32 Gthinkfunc_t::GetNextThinkTick() const {
    return GetSchemaValue<int32>(m_ptr, "thinkfunc_t", "m_nNextThinkTick");
}
void Gthinkfunc_t::SetNextThinkTick(int32 value) {
    SetSchemaValue(m_ptr, "thinkfunc_t", "m_nNextThinkTick", true, value);
}
int32 Gthinkfunc_t::GetLastThinkTick() const {
    return GetSchemaValue<int32>(m_ptr, "thinkfunc_t", "m_nLastThinkTick");
}
void Gthinkfunc_t::SetLastThinkTick(int32 value) {
    SetSchemaValue(m_ptr, "thinkfunc_t", "m_nLastThinkTick", true, value);
}
std::string Gthinkfunc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gthinkfunc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassthinkfunc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gthinkfunc_t>("thinkfunc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Context", &Gthinkfunc_t::GetContext, &Gthinkfunc_t::SetContext)
        .addProperty("NextThinkTick", &Gthinkfunc_t::GetNextThinkTick, &Gthinkfunc_t::SetNextThinkTick)
        .addProperty("LastThinkTick", &Gthinkfunc_t::GetLastThinkTick, &Gthinkfunc_t::SetLastThinkTick)
        .addFunction("ToPtr", &Gthinkfunc_t::ToPtr)
        .addFunction("IsValid", &Gthinkfunc_t::IsValid)
        .endClass();
}