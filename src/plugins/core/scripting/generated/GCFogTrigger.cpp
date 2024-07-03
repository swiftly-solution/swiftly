#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFogTrigger::GCFogTrigger(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFogTrigger::GCFogTrigger(void *ptr) {
    m_ptr = ptr;
}
Gfogparams_t GCFogTrigger::GetFog() const {
    Gfogparams_t value(GetSchemaPtr(m_ptr, "CFogTrigger", "m_fog"));
    return value;
}
void GCFogTrigger::SetFog(Gfogparams_t value) {
    SetSchemaValue(m_ptr, "CFogTrigger", "m_fog", false, value);
}
std::string GCFogTrigger::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFogTrigger::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCFogTrigger::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCFogTrigger::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFogTrigger(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFogTrigger>("CFogTrigger")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Fog", &GCFogTrigger::GetFog, &GCFogTrigger::SetFog)
        .addProperty("Parent", &GCFogTrigger::GetParent, &GCFogTrigger::SetParent)
        .addFunction("ToPtr", &GCFogTrigger::ToPtr)
        .addFunction("IsValid", &GCFogTrigger::IsValid)
        .endClass();
}