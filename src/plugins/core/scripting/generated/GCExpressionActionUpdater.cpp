#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCExpressionActionUpdater::GCExpressionActionUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCExpressionActionUpdater::GCExpressionActionUpdater(void *ptr) {
    m_ptr = ptr;
}
GCAnimParamHandle GCExpressionActionUpdater::GetParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CExpressionActionUpdater", "m_hParam"));
    return value;
}
void GCExpressionActionUpdater::SetParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CExpressionActionUpdater", "m_hParam", false, value);
}
uint64_t GCExpressionActionUpdater::GetParamType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CExpressionActionUpdater", "m_eParamType");
}
void GCExpressionActionUpdater::SetParamType(uint64_t value) {
    SetSchemaValue(m_ptr, "CExpressionActionUpdater", "m_eParamType", false, value);
}
GAnimScriptHandle GCExpressionActionUpdater::GetScript() const {
    GAnimScriptHandle value(GetSchemaPtr(m_ptr, "CExpressionActionUpdater", "m_hScript"));
    return value;
}
void GCExpressionActionUpdater::SetScript(GAnimScriptHandle value) {
    SetSchemaValue(m_ptr, "CExpressionActionUpdater", "m_hScript", false, value);
}
std::string GCExpressionActionUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCExpressionActionUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimActionUpdater GCExpressionActionUpdater::GetParent() const {
    GCAnimActionUpdater value(m_ptr);
    return value;
}
void GCExpressionActionUpdater::SetParent(GCAnimActionUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCExpressionActionUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCExpressionActionUpdater>("CExpressionActionUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Param", &GCExpressionActionUpdater::GetParam, &GCExpressionActionUpdater::SetParam)
        .addProperty("ParamType", &GCExpressionActionUpdater::GetParamType, &GCExpressionActionUpdater::SetParamType)
        .addProperty("Script", &GCExpressionActionUpdater::GetScript, &GCExpressionActionUpdater::SetScript)
        .addProperty("Parent", &GCExpressionActionUpdater::GetParent, &GCExpressionActionUpdater::SetParent)
        .addFunction("ToPtr", &GCExpressionActionUpdater::ToPtr)
        .addFunction("IsValid", &GCExpressionActionUpdater::IsValid)
        .endClass();
}