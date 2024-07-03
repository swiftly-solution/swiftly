#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncTimescale::GCFuncTimescale(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncTimescale::GCFuncTimescale(void *ptr) {
    m_ptr = ptr;
}
float GCFuncTimescale::GetDesiredTimescale() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTimescale", "m_flDesiredTimescale");
}
void GCFuncTimescale::SetDesiredTimescale(float value) {
    SetSchemaValue(m_ptr, "CFuncTimescale", "m_flDesiredTimescale", false, value);
}
float GCFuncTimescale::GetAcceleration() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTimescale", "m_flAcceleration");
}
void GCFuncTimescale::SetAcceleration(float value) {
    SetSchemaValue(m_ptr, "CFuncTimescale", "m_flAcceleration", false, value);
}
float GCFuncTimescale::GetMinBlendRate() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTimescale", "m_flMinBlendRate");
}
void GCFuncTimescale::SetMinBlendRate(float value) {
    SetSchemaValue(m_ptr, "CFuncTimescale", "m_flMinBlendRate", false, value);
}
float GCFuncTimescale::GetBlendDeltaMultiplier() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTimescale", "m_flBlendDeltaMultiplier");
}
void GCFuncTimescale::SetBlendDeltaMultiplier(float value) {
    SetSchemaValue(m_ptr, "CFuncTimescale", "m_flBlendDeltaMultiplier", false, value);
}
bool GCFuncTimescale::GetIsStarted() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncTimescale", "m_isStarted");
}
void GCFuncTimescale::SetIsStarted(bool value) {
    SetSchemaValue(m_ptr, "CFuncTimescale", "m_isStarted", false, value);
}
std::string GCFuncTimescale::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncTimescale::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCFuncTimescale::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCFuncTimescale::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncTimescale(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTimescale>("CFuncTimescale")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DesiredTimescale", &GCFuncTimescale::GetDesiredTimescale, &GCFuncTimescale::SetDesiredTimescale)
        .addProperty("Acceleration", &GCFuncTimescale::GetAcceleration, &GCFuncTimescale::SetAcceleration)
        .addProperty("MinBlendRate", &GCFuncTimescale::GetMinBlendRate, &GCFuncTimescale::SetMinBlendRate)
        .addProperty("BlendDeltaMultiplier", &GCFuncTimescale::GetBlendDeltaMultiplier, &GCFuncTimescale::SetBlendDeltaMultiplier)
        .addProperty("IsStarted", &GCFuncTimescale::GetIsStarted, &GCFuncTimescale::SetIsStarted)
        .addProperty("Parent", &GCFuncTimescale::GetParent, &GCFuncTimescale::SetParent)
        .addFunction("ToPtr", &GCFuncTimescale::ToPtr)
        .addFunction("IsValid", &GCFuncTimescale::IsValid)
        .endClass();
}