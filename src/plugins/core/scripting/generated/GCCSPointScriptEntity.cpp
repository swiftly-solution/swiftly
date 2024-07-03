#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPointScriptEntity::GCCSPointScriptEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPointScriptEntity::GCCSPointScriptEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSPointScriptEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPointScriptEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCCSPointScriptEntity::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCCSPointScriptEntity::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPointScriptEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptEntity>("CCSPointScriptEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSPointScriptEntity::GetParent, &GCCSPointScriptEntity::SetParent)
        .addFunction("ToPtr", &GCCSPointScriptEntity::ToPtr)
        .addFunction("IsValid", &GCCSPointScriptEntity::IsValid)
        .endClass();
}