#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCPPScriptComponentUpdater::GCCPPScriptComponentUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCPPScriptComponentUpdater::GCCPPScriptComponentUpdater(void *ptr) {
    m_ptr = ptr;
}
std::string GCCPPScriptComponentUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCPPScriptComponentUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimComponentUpdater GCCPPScriptComponentUpdater::GetParent() const {
    GCAnimComponentUpdater value(m_ptr);
    return value;
}
void GCCPPScriptComponentUpdater::SetParent(GCAnimComponentUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCPPScriptComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCPPScriptComponentUpdater>("CCPPScriptComponentUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCPPScriptComponentUpdater::GetParent, &GCCPPScriptComponentUpdater::SetParent)
        .addFunction("ToPtr", &GCCPPScriptComponentUpdater::ToPtr)
        .addFunction("IsValid", &GCCPPScriptComponentUpdater::IsValid)
        .endClass();
}