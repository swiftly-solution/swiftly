#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTextureBasedAnimatable::GCTextureBasedAnimatable(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTextureBasedAnimatable::GCTextureBasedAnimatable(void *ptr) {
    m_ptr = ptr;
}
bool GCTextureBasedAnimatable::GetLoop() const {
    return GetSchemaValue<bool>(m_ptr, "CTextureBasedAnimatable", "m_bLoop");
}
void GCTextureBasedAnimatable::SetLoop(bool value) {
    SetSchemaValue(m_ptr, "CTextureBasedAnimatable", "m_bLoop", false, value);
}
float GCTextureBasedAnimatable::GetFPS() const {
    return GetSchemaValue<float>(m_ptr, "CTextureBasedAnimatable", "m_flFPS");
}
void GCTextureBasedAnimatable::SetFPS(float value) {
    SetSchemaValue(m_ptr, "CTextureBasedAnimatable", "m_flFPS", false, value);
}
Vector GCTextureBasedAnimatable::GetAnimationBoundsMin() const {
    return GetSchemaValue<Vector>(m_ptr, "CTextureBasedAnimatable", "m_vAnimationBoundsMin");
}
void GCTextureBasedAnimatable::SetAnimationBoundsMin(Vector value) {
    SetSchemaValue(m_ptr, "CTextureBasedAnimatable", "m_vAnimationBoundsMin", false, value);
}
Vector GCTextureBasedAnimatable::GetAnimationBoundsMax() const {
    return GetSchemaValue<Vector>(m_ptr, "CTextureBasedAnimatable", "m_vAnimationBoundsMax");
}
void GCTextureBasedAnimatable::SetAnimationBoundsMax(Vector value) {
    SetSchemaValue(m_ptr, "CTextureBasedAnimatable", "m_vAnimationBoundsMax", false, value);
}
float GCTextureBasedAnimatable::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CTextureBasedAnimatable", "m_flStartTime");
}
void GCTextureBasedAnimatable::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "CTextureBasedAnimatable", "m_flStartTime", false, value);
}
float GCTextureBasedAnimatable::GetStartFrame() const {
    return GetSchemaValue<float>(m_ptr, "CTextureBasedAnimatable", "m_flStartFrame");
}
void GCTextureBasedAnimatable::SetStartFrame(float value) {
    SetSchemaValue(m_ptr, "CTextureBasedAnimatable", "m_flStartFrame", false, value);
}
std::string GCTextureBasedAnimatable::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTextureBasedAnimatable::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCTextureBasedAnimatable::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCTextureBasedAnimatable::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTextureBasedAnimatable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTextureBasedAnimatable>("CTextureBasedAnimatable")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Loop", &GCTextureBasedAnimatable::GetLoop, &GCTextureBasedAnimatable::SetLoop)
        .addProperty("FPS", &GCTextureBasedAnimatable::GetFPS, &GCTextureBasedAnimatable::SetFPS)
        .addProperty("AnimationBoundsMin", &GCTextureBasedAnimatable::GetAnimationBoundsMin, &GCTextureBasedAnimatable::SetAnimationBoundsMin)
        .addProperty("AnimationBoundsMax", &GCTextureBasedAnimatable::GetAnimationBoundsMax, &GCTextureBasedAnimatable::SetAnimationBoundsMax)
        .addProperty("StartTime", &GCTextureBasedAnimatable::GetStartTime, &GCTextureBasedAnimatable::SetStartTime)
        .addProperty("StartFrame", &GCTextureBasedAnimatable::GetStartFrame, &GCTextureBasedAnimatable::SetStartFrame)
        .addProperty("Parent", &GCTextureBasedAnimatable::GetParent, &GCTextureBasedAnimatable::SetParent)
        .addFunction("ToPtr", &GCTextureBasedAnimatable::ToPtr)
        .addFunction("IsValid", &GCTextureBasedAnimatable::IsValid)
        .endClass();
}