#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFogController::GCFogController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFogController::GCFogController(void *ptr) {
    m_ptr = ptr;
}
Gfogparams_t GCFogController::GetFog() const {
    Gfogparams_t value(GetSchemaPtr(m_ptr, "CFogController", "m_fog"));
    return value;
}
void GCFogController::SetFog(Gfogparams_t value) {
    SetSchemaValue(m_ptr, "CFogController", "m_fog", false, value);
}
bool GCFogController::GetUseAngles() const {
    return GetSchemaValue<bool>(m_ptr, "CFogController", "m_bUseAngles");
}
void GCFogController::SetUseAngles(bool value) {
    SetSchemaValue(m_ptr, "CFogController", "m_bUseAngles", false, value);
}
int32_t GCFogController::GetChangedVariables() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFogController", "m_iChangedVariables");
}
void GCFogController::SetChangedVariables(int32_t value) {
    SetSchemaValue(m_ptr, "CFogController", "m_iChangedVariables", false, value);
}
std::string GCFogController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFogController::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCFogController::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCFogController::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFogController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFogController>("CFogController")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Fog", &GCFogController::GetFog, &GCFogController::SetFog)
        .addProperty("UseAngles", &GCFogController::GetUseAngles, &GCFogController::SetUseAngles)
        .addProperty("ChangedVariables", &GCFogController::GetChangedVariables, &GCFogController::SetChangedVariables)
        .addProperty("Parent", &GCFogController::GetParent, &GCFogController::SetParent)
        .addFunction("ToPtr", &GCFogController::ToPtr)
        .addFunction("IsValid", &GCFogController::IsValid)
        .endClass();
}