#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncTrain::GCFuncTrain(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncTrain::GCFuncTrain(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCFuncTrain::GetCurrentTarget() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CFuncTrain", "m_hCurrentTarget"));
    return value;
}
void GCFuncTrain::SetCurrentTarget(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'CurrentTarget' is not possible.\n");
}
bool GCFuncTrain::GetActivated() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncTrain", "m_activated");
}
void GCFuncTrain::SetActivated(bool value) {
    SetSchemaValue(m_ptr, "CFuncTrain", "m_activated", false, value);
}
GCBaseEntity GCFuncTrain::GetEnemy() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CFuncTrain", "m_hEnemy"));
    return value;
}
void GCFuncTrain::SetEnemy(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Enemy' is not possible.\n");
}
float GCFuncTrain::GetBlockDamage() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrain", "m_flBlockDamage");
}
void GCFuncTrain::SetBlockDamage(float value) {
    SetSchemaValue(m_ptr, "CFuncTrain", "m_flBlockDamage", false, value);
}
float GCFuncTrain::GetNextBlockTime() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrain", "m_flNextBlockTime");
}
void GCFuncTrain::SetNextBlockTime(float value) {
    SetSchemaValue(m_ptr, "CFuncTrain", "m_flNextBlockTime", false, value);
}
std::string GCFuncTrain::GetLastTarget() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrain", "m_iszLastTarget").String();
}
void GCFuncTrain::SetLastTarget(std::string value) {
    SetSchemaValue(m_ptr, "CFuncTrain", "m_iszLastTarget", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncTrain::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncTrain::IsValid() {
    return (m_ptr != nullptr);
}
GCBasePlatTrain GCFuncTrain::GetParent() const {
    GCBasePlatTrain value(m_ptr);
    return value;
}
void GCFuncTrain::SetParent(GCBasePlatTrain value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncTrain(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTrain>("CFuncTrain")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CurrentTarget", &GCFuncTrain::GetCurrentTarget, &GCFuncTrain::SetCurrentTarget)
        .addProperty("Activated", &GCFuncTrain::GetActivated, &GCFuncTrain::SetActivated)
        .addProperty("Enemy", &GCFuncTrain::GetEnemy, &GCFuncTrain::SetEnemy)
        .addProperty("BlockDamage", &GCFuncTrain::GetBlockDamage, &GCFuncTrain::SetBlockDamage)
        .addProperty("NextBlockTime", &GCFuncTrain::GetNextBlockTime, &GCFuncTrain::SetNextBlockTime)
        .addProperty("LastTarget", &GCFuncTrain::GetLastTarget, &GCFuncTrain::SetLastTarget)
        .addProperty("Parent", &GCFuncTrain::GetParent, &GCFuncTrain::SetParent)
        .addFunction("ToPtr", &GCFuncTrain::ToPtr)
        .addFunction("IsValid", &GCFuncTrain::IsValid)
        .endClass();
}