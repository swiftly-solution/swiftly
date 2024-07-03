#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerBlender::GCVoiceContainerBlender(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerBlender::GCVoiceContainerBlender(void *ptr) {
    m_ptr = ptr;
}
float GCVoiceContainerBlender::GetBlendFactor() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerBlender", "m_flBlendFactor");
}
void GCVoiceContainerBlender::SetBlendFactor(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerBlender", "m_flBlendFactor", false, value);
}
std::string GCVoiceContainerBlender::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerBlender::IsValid() {
    return (m_ptr != nullptr);
}
GCVoiceContainerBase GCVoiceContainerBlender::GetParent() const {
    GCVoiceContainerBase value(m_ptr);
    return value;
}
void GCVoiceContainerBlender::SetParent(GCVoiceContainerBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCVoiceContainerBlender(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerBlender>("CVoiceContainerBlender")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BlendFactor", &GCVoiceContainerBlender::GetBlendFactor, &GCVoiceContainerBlender::SetBlendFactor)
        .addProperty("Parent", &GCVoiceContainerBlender::GetParent, &GCVoiceContainerBlender::SetParent)
        .addFunction("ToPtr", &GCVoiceContainerBlender::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerBlender::IsValid)
        .endClass();
}