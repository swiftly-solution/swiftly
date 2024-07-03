#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPointScript::GCCSPointScript(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPointScript::GCCSPointScript(void *ptr) {
    m_ptr = ptr;
}
GCCSPointScriptEntity GCCSPointScript::GetParent() const {
    GCCSPointScriptEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPointScript", "m_pParent"));
    return value;
}
void GCCSPointScript::SetParent(GCCSPointScriptEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
std::string GCCSPointScript::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPointScript::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCSPointScript(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScript>("CCSPointScript")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSPointScript::GetParent, &GCCSPointScript::SetParent)
        .addFunction("ToPtr", &GCCSPointScript::ToPtr)
        .addFunction("IsValid", &GCCSPointScript::IsValid)
        .endClass();
}