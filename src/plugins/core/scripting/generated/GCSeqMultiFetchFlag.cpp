#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqMultiFetchFlag::GCSeqMultiFetchFlag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqMultiFetchFlag::GCSeqMultiFetchFlag(void *ptr) {
    m_ptr = ptr;
}
bool GCSeqMultiFetchFlag::GetRealtime() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetchFlag", "m_bRealtime");
}
void GCSeqMultiFetchFlag::SetRealtime(bool value) {
    SetSchemaValue(m_ptr, "CSeqMultiFetchFlag", "m_bRealtime", false, value);
}
bool GCSeqMultiFetchFlag::GetCylepose() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetchFlag", "m_bCylepose");
}
void GCSeqMultiFetchFlag::SetCylepose(bool value) {
    SetSchemaValue(m_ptr, "CSeqMultiFetchFlag", "m_bCylepose", false, value);
}
bool GCSeqMultiFetchFlag::Get0D() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetchFlag", "m_b0D");
}
void GCSeqMultiFetchFlag::Set0D(bool value) {
    SetSchemaValue(m_ptr, "CSeqMultiFetchFlag", "m_b0D", false, value);
}
bool GCSeqMultiFetchFlag::Get1D() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetchFlag", "m_b1D");
}
void GCSeqMultiFetchFlag::Set1D(bool value) {
    SetSchemaValue(m_ptr, "CSeqMultiFetchFlag", "m_b1D", false, value);
}
bool GCSeqMultiFetchFlag::Get2D() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetchFlag", "m_b2D");
}
void GCSeqMultiFetchFlag::Set2D(bool value) {
    SetSchemaValue(m_ptr, "CSeqMultiFetchFlag", "m_b2D", false, value);
}
bool GCSeqMultiFetchFlag::Get2D_TRI() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqMultiFetchFlag", "m_b2D_TRI");
}
void GCSeqMultiFetchFlag::Set2D_TRI(bool value) {
    SetSchemaValue(m_ptr, "CSeqMultiFetchFlag", "m_b2D_TRI", false, value);
}
std::string GCSeqMultiFetchFlag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqMultiFetchFlag::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqMultiFetchFlag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqMultiFetchFlag>("CSeqMultiFetchFlag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Realtime", &GCSeqMultiFetchFlag::GetRealtime, &GCSeqMultiFetchFlag::SetRealtime)
        .addProperty("Cylepose", &GCSeqMultiFetchFlag::GetCylepose, &GCSeqMultiFetchFlag::SetCylepose)
        .addProperty("0D", &GCSeqMultiFetchFlag::Get0D, &GCSeqMultiFetchFlag::Set0D)
        .addProperty("1D", &GCSeqMultiFetchFlag::Get1D, &GCSeqMultiFetchFlag::Set1D)
        .addProperty("2D", &GCSeqMultiFetchFlag::Get2D, &GCSeqMultiFetchFlag::Set2D)
        .addProperty("2D_TRI", &GCSeqMultiFetchFlag::Get2D_TRI, &GCSeqMultiFetchFlag::Set2D_TRI)
        .addFunction("ToPtr", &GCSeqMultiFetchFlag::ToPtr)
        .addFunction("IsValid", &GCSeqMultiFetchFlag::IsValid)
        .endClass();
}