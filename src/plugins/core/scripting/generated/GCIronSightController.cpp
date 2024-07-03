#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCIronSightController::GCIronSightController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCIronSightController::GCIronSightController(void *ptr) {
    m_ptr = ptr;
}
bool GCIronSightController::GetIronSightAvailable() const {
    return GetSchemaValue<bool>(m_ptr, "CIronSightController", "m_bIronSightAvailable");
}
void GCIronSightController::SetIronSightAvailable(bool value) {
    SetSchemaValue(m_ptr, "CIronSightController", "m_bIronSightAvailable", false, value);
}
float GCIronSightController::GetIronSightAmount() const {
    return GetSchemaValue<float>(m_ptr, "CIronSightController", "m_flIronSightAmount");
}
void GCIronSightController::SetIronSightAmount(float value) {
    SetSchemaValue(m_ptr, "CIronSightController", "m_flIronSightAmount", false, value);
}
float GCIronSightController::GetIronSightAmountGained() const {
    return GetSchemaValue<float>(m_ptr, "CIronSightController", "m_flIronSightAmountGained");
}
void GCIronSightController::SetIronSightAmountGained(float value) {
    SetSchemaValue(m_ptr, "CIronSightController", "m_flIronSightAmountGained", false, value);
}
float GCIronSightController::GetIronSightAmountBiased() const {
    return GetSchemaValue<float>(m_ptr, "CIronSightController", "m_flIronSightAmountBiased");
}
void GCIronSightController::SetIronSightAmountBiased(float value) {
    SetSchemaValue(m_ptr, "CIronSightController", "m_flIronSightAmountBiased", false, value);
}
std::string GCIronSightController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCIronSightController::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCIronSightController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCIronSightController>("CIronSightController")
        .addConstructor<void (*)(std::string)>()
        .addProperty("IronSightAvailable", &GCIronSightController::GetIronSightAvailable, &GCIronSightController::SetIronSightAvailable)
        .addProperty("IronSightAmount", &GCIronSightController::GetIronSightAmount, &GCIronSightController::SetIronSightAmount)
        .addProperty("IronSightAmountGained", &GCIronSightController::GetIronSightAmountGained, &GCIronSightController::SetIronSightAmountGained)
        .addProperty("IronSightAmountBiased", &GCIronSightController::GetIronSightAmountBiased, &GCIronSightController::SetIronSightAmountBiased)
        .addFunction("ToPtr", &GCIronSightController::ToPtr)
        .addFunction("IsValid", &GCIronSightController::IsValid)
        .endClass();
}