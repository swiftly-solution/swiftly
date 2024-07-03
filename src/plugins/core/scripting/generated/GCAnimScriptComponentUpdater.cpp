#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimScriptComponentUpdater::GCAnimScriptComponentUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimScriptComponentUpdater::GCAnimScriptComponentUpdater(void *ptr) {
    m_ptr = ptr;
}
GAnimScriptHandle GCAnimScriptComponentUpdater::GetScript() const {
    GAnimScriptHandle value(GetSchemaPtr(m_ptr, "CAnimScriptComponentUpdater", "m_hScript"));
    return value;
}
void GCAnimScriptComponentUpdater::SetScript(GAnimScriptHandle value) {
    SetSchemaValue(m_ptr, "CAnimScriptComponentUpdater", "m_hScript", false, value);
}
std::string GCAnimScriptComponentUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimScriptComponentUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimComponentUpdater GCAnimScriptComponentUpdater::GetParent() const {
    GCAnimComponentUpdater value(m_ptr);
    return value;
}
void GCAnimScriptComponentUpdater::SetParent(GCAnimComponentUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAnimScriptComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimScriptComponentUpdater>("CAnimScriptComponentUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Script", &GCAnimScriptComponentUpdater::GetScript, &GCAnimScriptComponentUpdater::SetScript)
        .addProperty("Parent", &GCAnimScriptComponentUpdater::GetParent, &GCAnimScriptComponentUpdater::SetParent)
        .addFunction("ToPtr", &GCAnimScriptComponentUpdater::ToPtr)
        .addFunction("IsValid", &GCAnimScriptComponentUpdater::IsValid)
        .endClass();
}