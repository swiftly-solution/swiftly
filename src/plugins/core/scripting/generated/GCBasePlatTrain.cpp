#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBasePlatTrain::GCBasePlatTrain(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBasePlatTrain::GCBasePlatTrain(void *ptr) {
    m_ptr = ptr;
}
std::string GCBasePlatTrain::GetNoiseMoving() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePlatTrain", "m_NoiseMoving").String();
}
void GCBasePlatTrain::SetNoiseMoving(std::string value) {
    SetSchemaValue(m_ptr, "CBasePlatTrain", "m_NoiseMoving", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBasePlatTrain::GetNoiseArrived() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBasePlatTrain", "m_NoiseArrived").String();
}
void GCBasePlatTrain::SetNoiseArrived(std::string value) {
    SetSchemaValue(m_ptr, "CBasePlatTrain", "m_NoiseArrived", false, CUtlSymbolLarge(value.c_str()));
}
float GCBasePlatTrain::GetVolume() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlatTrain", "m_volume");
}
void GCBasePlatTrain::SetVolume(float value) {
    SetSchemaValue(m_ptr, "CBasePlatTrain", "m_volume", false, value);
}
float GCBasePlatTrain::GetTWidth() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlatTrain", "m_flTWidth");
}
void GCBasePlatTrain::SetTWidth(float value) {
    SetSchemaValue(m_ptr, "CBasePlatTrain", "m_flTWidth", false, value);
}
float GCBasePlatTrain::GetTLength() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlatTrain", "m_flTLength");
}
void GCBasePlatTrain::SetTLength(float value) {
    SetSchemaValue(m_ptr, "CBasePlatTrain", "m_flTLength", false, value);
}
std::string GCBasePlatTrain::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBasePlatTrain::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseToggle GCBasePlatTrain::GetParent() const {
    GCBaseToggle value(m_ptr);
    return value;
}
void GCBasePlatTrain::SetParent(GCBaseToggle value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBasePlatTrain(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlatTrain>("CBasePlatTrain")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NoiseMoving", &GCBasePlatTrain::GetNoiseMoving, &GCBasePlatTrain::SetNoiseMoving)
        .addProperty("NoiseArrived", &GCBasePlatTrain::GetNoiseArrived, &GCBasePlatTrain::SetNoiseArrived)
        .addProperty("Volume", &GCBasePlatTrain::GetVolume, &GCBasePlatTrain::SetVolume)
        .addProperty("TWidth", &GCBasePlatTrain::GetTWidth, &GCBasePlatTrain::SetTWidth)
        .addProperty("TLength", &GCBasePlatTrain::GetTLength, &GCBasePlatTrain::SetTLength)
        .addProperty("Parent", &GCBasePlatTrain::GetParent, &GCBasePlatTrain::SetParent)
        .addFunction("ToPtr", &GCBasePlatTrain::ToPtr)
        .addFunction("IsValid", &GCBasePlatTrain::IsValid)
        .endClass();
}