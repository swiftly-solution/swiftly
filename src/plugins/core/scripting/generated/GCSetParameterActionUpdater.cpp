#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSetParameterActionUpdater::GCSetParameterActionUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSetParameterActionUpdater::GCSetParameterActionUpdater(void *ptr) {
    m_ptr = ptr;
}
GCAnimParamHandle GCSetParameterActionUpdater::GetParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CSetParameterActionUpdater", "m_hParam"));
    return value;
}
void GCSetParameterActionUpdater::SetParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CSetParameterActionUpdater", "m_hParam", false, value);
}
std::string GCSetParameterActionUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSetParameterActionUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimActionUpdater GCSetParameterActionUpdater::GetParent() const {
    GCAnimActionUpdater value(m_ptr);
    return value;
}
void GCSetParameterActionUpdater::SetParent(GCAnimActionUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSetParameterActionUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSetParameterActionUpdater>("CSetParameterActionUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Param", &GCSetParameterActionUpdater::GetParam, &GCSetParameterActionUpdater::SetParam)
        .addProperty("Parent", &GCSetParameterActionUpdater::GetParent, &GCSetParameterActionUpdater::SetParent)
        .addFunction("ToPtr", &GCSetParameterActionUpdater::ToPtr)
        .addFunction("IsValid", &GCSetParameterActionUpdater::IsValid)
        .endClass();
}