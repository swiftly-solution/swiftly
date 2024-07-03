#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gsky3dparams_t::Gsky3dparams_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gsky3dparams_t::Gsky3dparams_t(void *ptr) {
    m_ptr = ptr;
}
int16_t Gsky3dparams_t::GetScale() const {
    return GetSchemaValue<int16_t>(m_ptr, "sky3dparams_t", "scale");
}
void Gsky3dparams_t::SetScale(int16_t value) {
    SetSchemaValue(m_ptr, "sky3dparams_t", "scale", true, value);
}
Vector Gsky3dparams_t::GetOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "sky3dparams_t", "origin");
}
void Gsky3dparams_t::SetOrigin(Vector value) {
    SetSchemaValue(m_ptr, "sky3dparams_t", "origin", true, value);
}
bool Gsky3dparams_t::GetClip3DSkyBoxNearToWorldFar() const {
    return GetSchemaValue<bool>(m_ptr, "sky3dparams_t", "bClip3DSkyBoxNearToWorldFar");
}
void Gsky3dparams_t::SetClip3DSkyBoxNearToWorldFar(bool value) {
    SetSchemaValue(m_ptr, "sky3dparams_t", "bClip3DSkyBoxNearToWorldFar", true, value);
}
float Gsky3dparams_t::GetClip3DSkyBoxNearToWorldFarOffset() const {
    return GetSchemaValue<float>(m_ptr, "sky3dparams_t", "flClip3DSkyBoxNearToWorldFarOffset");
}
void Gsky3dparams_t::SetClip3DSkyBoxNearToWorldFarOffset(float value) {
    SetSchemaValue(m_ptr, "sky3dparams_t", "flClip3DSkyBoxNearToWorldFarOffset", true, value);
}
Gfogparams_t Gsky3dparams_t::GetFog() const {
    Gfogparams_t value(GetSchemaPtr(m_ptr, "sky3dparams_t", "fog"));
    return value;
}
void Gsky3dparams_t::SetFog(Gfogparams_t value) {
    SetSchemaValue(m_ptr, "sky3dparams_t", "fog", true, value);
}
WorldGroupId_t Gsky3dparams_t::GetWorldGroupID() const {
    return GetSchemaValue<WorldGroupId_t>(m_ptr, "sky3dparams_t", "m_nWorldGroupID");
}
void Gsky3dparams_t::SetWorldGroupID(WorldGroupId_t value) {
    SetSchemaValue(m_ptr, "sky3dparams_t", "m_nWorldGroupID", true, value);
}
std::string Gsky3dparams_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gsky3dparams_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClasssky3dparams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gsky3dparams_t>("sky3dparams_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Scale", &Gsky3dparams_t::GetScale, &Gsky3dparams_t::SetScale)
        .addProperty("Origin", &Gsky3dparams_t::GetOrigin, &Gsky3dparams_t::SetOrigin)
        .addProperty("Clip3DSkyBoxNearToWorldFar", &Gsky3dparams_t::GetClip3DSkyBoxNearToWorldFar, &Gsky3dparams_t::SetClip3DSkyBoxNearToWorldFar)
        .addProperty("Clip3DSkyBoxNearToWorldFarOffset", &Gsky3dparams_t::GetClip3DSkyBoxNearToWorldFarOffset, &Gsky3dparams_t::SetClip3DSkyBoxNearToWorldFarOffset)
        .addProperty("Fog", &Gsky3dparams_t::GetFog, &Gsky3dparams_t::SetFog)
        .addProperty("WorldGroupID", &Gsky3dparams_t::GetWorldGroupID, &Gsky3dparams_t::SetWorldGroupID)
        .addFunction("ToPtr", &Gsky3dparams_t::ToPtr)
        .addFunction("IsValid", &Gsky3dparams_t::IsValid)
        .endClass();
}