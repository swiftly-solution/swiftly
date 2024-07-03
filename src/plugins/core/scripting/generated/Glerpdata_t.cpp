#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Glerpdata_t::Glerpdata_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Glerpdata_t::Glerpdata_t(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity Glerpdata_t::GetEnt() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "lerpdata_t", "m_hEnt"));
    return value;
}
void Glerpdata_t::SetEnt(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Ent' is not possible.\n");
}
uint64_t Glerpdata_t::GetMoveType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "lerpdata_t", "m_MoveType");
}
void Glerpdata_t::SetMoveType(uint64_t value) {
    SetSchemaValue(m_ptr, "lerpdata_t", "m_MoveType", true, value);
}
float Glerpdata_t::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "lerpdata_t", "m_flStartTime");
}
void Glerpdata_t::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "lerpdata_t", "m_flStartTime", true, value);
}
Vector Glerpdata_t::GetStartOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "lerpdata_t", "m_vecStartOrigin");
}
void Glerpdata_t::SetStartOrigin(Vector value) {
    SetSchemaValue(m_ptr, "lerpdata_t", "m_vecStartOrigin", true, value);
}
Quaternion Glerpdata_t::GetStartRot() const {
    return GetSchemaValue<Quaternion>(m_ptr, "lerpdata_t", "m_qStartRot");
}
void Glerpdata_t::SetStartRot(Quaternion value) {
    SetSchemaValue(m_ptr, "lerpdata_t", "m_qStartRot", true, value);
}
GParticleIndex_t Glerpdata_t::GetFXIndex() const {
    GParticleIndex_t value(GetSchemaPtr(m_ptr, "lerpdata_t", "m_nFXIndex"));
    return value;
}
void Glerpdata_t::SetFXIndex(GParticleIndex_t value) {
    SetSchemaValue(m_ptr, "lerpdata_t", "m_nFXIndex", true, value);
}
std::string Glerpdata_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Glerpdata_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClasslerpdata_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Glerpdata_t>("lerpdata_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Ent", &Glerpdata_t::GetEnt, &Glerpdata_t::SetEnt)
        .addProperty("MoveType", &Glerpdata_t::GetMoveType, &Glerpdata_t::SetMoveType)
        .addProperty("StartTime", &Glerpdata_t::GetStartTime, &Glerpdata_t::SetStartTime)
        .addProperty("StartOrigin", &Glerpdata_t::GetStartOrigin, &Glerpdata_t::SetStartOrigin)
        .addProperty("StartRot", &Glerpdata_t::GetStartRot, &Glerpdata_t::SetStartRot)
        .addProperty("FXIndex", &Glerpdata_t::GetFXIndex, &Glerpdata_t::SetFXIndex)
        .addFunction("ToPtr", &Glerpdata_t::ToPtr)
        .addFunction("IsValid", &Glerpdata_t::IsValid)
        .endClass();
}