#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvLaser::GCEnvLaser(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvLaser::GCEnvLaser(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvLaser::GetLaserTarget() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvLaser", "m_iszLaserTarget").String();
}
void GCEnvLaser::SetLaserTarget(std::string value) {
    SetSchemaValue(m_ptr, "CEnvLaser", "m_iszLaserTarget", false, CUtlSymbolLarge(value.c_str()));
}
GCSprite GCEnvLaser::GetSprite() const {
    GCSprite value(*GetSchemaValuePtr<void*>(m_ptr, "CEnvLaser", "m_pSprite"));
    return value;
}
void GCEnvLaser::SetSprite(GCSprite* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Sprite' is not possible.\n");
}
std::string GCEnvLaser::GetSpriteName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvLaser", "m_iszSpriteName").String();
}
void GCEnvLaser::SetSpriteName(std::string value) {
    SetSchemaValue(m_ptr, "CEnvLaser", "m_iszSpriteName", false, CUtlSymbolLarge(value.c_str()));
}
Vector GCEnvLaser::GetFirePosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvLaser", "m_firePosition");
}
void GCEnvLaser::SetFirePosition(Vector value) {
    SetSchemaValue(m_ptr, "CEnvLaser", "m_firePosition", false, value);
}
float GCEnvLaser::GetStartFrame() const {
    return GetSchemaValue<float>(m_ptr, "CEnvLaser", "m_flStartFrame");
}
void GCEnvLaser::SetStartFrame(float value) {
    SetSchemaValue(m_ptr, "CEnvLaser", "m_flStartFrame", false, value);
}
std::string GCEnvLaser::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvLaser::IsValid() {
    return (m_ptr != nullptr);
}
GCBeam GCEnvLaser::GetParent() const {
    GCBeam value(m_ptr);
    return value;
}
void GCEnvLaser::SetParent(GCBeam value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvLaser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvLaser>("CEnvLaser")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LaserTarget", &GCEnvLaser::GetLaserTarget, &GCEnvLaser::SetLaserTarget)
        .addProperty("Sprite", &GCEnvLaser::GetSprite, &GCEnvLaser::SetSprite)
        .addProperty("SpriteName", &GCEnvLaser::GetSpriteName, &GCEnvLaser::SetSpriteName)
        .addProperty("FirePosition", &GCEnvLaser::GetFirePosition, &GCEnvLaser::SetFirePosition)
        .addProperty("StartFrame", &GCEnvLaser::GetStartFrame, &GCEnvLaser::SetStartFrame)
        .addProperty("Parent", &GCEnvLaser::GetParent, &GCEnvLaser::SetParent)
        .addFunction("ToPtr", &GCEnvLaser::ToPtr)
        .addFunction("IsValid", &GCEnvLaser::IsValid)
        .endClass();
}