#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeWorldCollisionParams_t::GFeWorldCollisionParams_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeWorldCollisionParams_t::GFeWorldCollisionParams_t(void *ptr) {
    m_ptr = ptr;
}
float GFeWorldCollisionParams_t::GetWorldFriction() const {
    return GetSchemaValue<float>(m_ptr, "FeWorldCollisionParams_t", "flWorldFriction");
}
void GFeWorldCollisionParams_t::SetWorldFriction(float value) {
    SetSchemaValue(m_ptr, "FeWorldCollisionParams_t", "flWorldFriction", true, value);
}
float GFeWorldCollisionParams_t::GetGroundFriction() const {
    return GetSchemaValue<float>(m_ptr, "FeWorldCollisionParams_t", "flGroundFriction");
}
void GFeWorldCollisionParams_t::SetGroundFriction(float value) {
    SetSchemaValue(m_ptr, "FeWorldCollisionParams_t", "flGroundFriction", true, value);
}
uint16_t GFeWorldCollisionParams_t::GetListBegin() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeWorldCollisionParams_t", "nListBegin");
}
void GFeWorldCollisionParams_t::SetListBegin(uint16_t value) {
    SetSchemaValue(m_ptr, "FeWorldCollisionParams_t", "nListBegin", true, value);
}
uint16_t GFeWorldCollisionParams_t::GetListEnd() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeWorldCollisionParams_t", "nListEnd");
}
void GFeWorldCollisionParams_t::SetListEnd(uint16_t value) {
    SetSchemaValue(m_ptr, "FeWorldCollisionParams_t", "nListEnd", true, value);
}
std::string GFeWorldCollisionParams_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeWorldCollisionParams_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeWorldCollisionParams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeWorldCollisionParams_t>("FeWorldCollisionParams_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WorldFriction", &GFeWorldCollisionParams_t::GetWorldFriction, &GFeWorldCollisionParams_t::SetWorldFriction)
        .addProperty("GroundFriction", &GFeWorldCollisionParams_t::GetGroundFriction, &GFeWorldCollisionParams_t::SetGroundFriction)
        .addProperty("ListBegin", &GFeWorldCollisionParams_t::GetListBegin, &GFeWorldCollisionParams_t::SetListBegin)
        .addProperty("ListEnd", &GFeWorldCollisionParams_t::GetListEnd, &GFeWorldCollisionParams_t::SetListEnd)
        .addFunction("ToPtr", &GFeWorldCollisionParams_t::ToPtr)
        .addFunction("IsValid", &GFeWorldCollisionParams_t::IsValid)
        .endClass();
}