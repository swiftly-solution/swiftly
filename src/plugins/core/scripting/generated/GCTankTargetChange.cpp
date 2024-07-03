#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTankTargetChange::GCTankTargetChange(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTankTargetChange::GCTankTargetChange(void *ptr) {
    m_ptr = ptr;
}
std::string GCTankTargetChange::GetNewTargetName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTankTargetChange", "m_newTargetName").String();
}
void GCTankTargetChange::SetNewTargetName(std::string value) {
    SetSchemaValue(m_ptr, "CTankTargetChange", "m_newTargetName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCTankTargetChange::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTankTargetChange::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCTankTargetChange::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCTankTargetChange::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTankTargetChange(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTankTargetChange>("CTankTargetChange")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NewTargetName", &GCTankTargetChange::GetNewTargetName, &GCTankTargetChange::SetNewTargetName)
        .addProperty("Parent", &GCTankTargetChange::GetParent, &GCTankTargetChange::SetParent)
        .addFunction("ToPtr", &GCTankTargetChange::ToPtr)
        .addFunction("IsValid", &GCTankTargetChange::IsValid)
        .endClass();
}