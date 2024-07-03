#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSoundOpvarTraceResult_t::GSoundOpvarTraceResult_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSoundOpvarTraceResult_t::GSoundOpvarTraceResult_t(void *ptr) {
    m_ptr = ptr;
}
Vector GSoundOpvarTraceResult_t::GetPos() const {
    return GetSchemaValue<Vector>(m_ptr, "SoundOpvarTraceResult_t", "vPos");
}
void GSoundOpvarTraceResult_t::SetPos(Vector value) {
    SetSchemaValue(m_ptr, "SoundOpvarTraceResult_t", "vPos", true, value);
}
bool GSoundOpvarTraceResult_t::GetDidHit() const {
    return GetSchemaValue<bool>(m_ptr, "SoundOpvarTraceResult_t", "bDidHit");
}
void GSoundOpvarTraceResult_t::SetDidHit(bool value) {
    SetSchemaValue(m_ptr, "SoundOpvarTraceResult_t", "bDidHit", true, value);
}
float GSoundOpvarTraceResult_t::GetDistSqrToCenter() const {
    return GetSchemaValue<float>(m_ptr, "SoundOpvarTraceResult_t", "flDistSqrToCenter");
}
void GSoundOpvarTraceResult_t::SetDistSqrToCenter(float value) {
    SetSchemaValue(m_ptr, "SoundOpvarTraceResult_t", "flDistSqrToCenter", true, value);
}
std::string GSoundOpvarTraceResult_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSoundOpvarTraceResult_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSoundOpvarTraceResult_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSoundOpvarTraceResult_t>("SoundOpvarTraceResult_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Pos", &GSoundOpvarTraceResult_t::GetPos, &GSoundOpvarTraceResult_t::SetPos)
        .addProperty("DidHit", &GSoundOpvarTraceResult_t::GetDidHit, &GSoundOpvarTraceResult_t::SetDidHit)
        .addProperty("DistSqrToCenter", &GSoundOpvarTraceResult_t::GetDistSqrToCenter, &GSoundOpvarTraceResult_t::SetDistSqrToCenter)
        .addFunction("ToPtr", &GSoundOpvarTraceResult_t::ToPtr)
        .addFunction("IsValid", &GSoundOpvarTraceResult_t::IsValid)
        .endClass();
}