#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSServerPointScriptEntity::GCCSServerPointScriptEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSServerPointScriptEntity::GCCSServerPointScriptEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSServerPointScriptEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSServerPointScriptEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCCSPointScriptEntity GCCSServerPointScriptEntity::GetParent() const {
    GCCSPointScriptEntity value(m_ptr);
    return value;
}
void GCCSServerPointScriptEntity::SetParent(GCCSPointScriptEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSServerPointScriptEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSServerPointScriptEntity>("CCSServerPointScriptEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSServerPointScriptEntity::GetParent, &GCCSServerPointScriptEntity::SetParent)
        .addFunction("ToPtr", &GCCSServerPointScriptEntity::ToPtr)
        .addFunction("IsValid", &GCCSServerPointScriptEntity::IsValid)
        .endClass();
}