#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvTracer::GCEnvTracer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvTracer::GCEnvTracer(void *ptr) {
    m_ptr = ptr;
}
Vector GCEnvTracer::GetEnd() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvTracer", "m_vecEnd");
}
void GCEnvTracer::SetEnd(Vector value) {
    SetSchemaValue(m_ptr, "CEnvTracer", "m_vecEnd", false, value);
}
float GCEnvTracer::GetDelay() const {
    return GetSchemaValue<float>(m_ptr, "CEnvTracer", "m_flDelay");
}
void GCEnvTracer::SetDelay(float value) {
    SetSchemaValue(m_ptr, "CEnvTracer", "m_flDelay", false, value);
}
std::string GCEnvTracer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvTracer::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvTracer::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvTracer::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvTracer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvTracer>("CEnvTracer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("End", &GCEnvTracer::GetEnd, &GCEnvTracer::SetEnd)
        .addProperty("Delay", &GCEnvTracer::GetDelay, &GCEnvTracer::SetDelay)
        .addProperty("Parent", &GCEnvTracer::GetParent, &GCEnvTracer::SetParent)
        .addFunction("ToPtr", &GCEnvTracer::ToPtr)
        .addFunction("IsValid", &GCEnvTracer::IsValid)
        .endClass();
}