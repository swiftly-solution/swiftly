#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncPropRespawnZone::GCFuncPropRespawnZone(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncPropRespawnZone::GCFuncPropRespawnZone(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncPropRespawnZone::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncPropRespawnZone::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCFuncPropRespawnZone::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCFuncPropRespawnZone::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncPropRespawnZone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncPropRespawnZone>("CFuncPropRespawnZone")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCFuncPropRespawnZone::GetParent, &GCFuncPropRespawnZone::SetParent)
        .addFunction("ToPtr", &GCFuncPropRespawnZone::ToPtr)
        .addFunction("IsValid", &GCFuncPropRespawnZone::IsValid)
        .endClass();
}