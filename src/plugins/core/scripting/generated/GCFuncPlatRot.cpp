#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncPlatRot::GCFuncPlatRot(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncPlatRot::GCFuncPlatRot(void *ptr) {
    m_ptr = ptr;
}
QAngle GCFuncPlatRot::GetEnd() const {
    return GetSchemaValue<QAngle>(m_ptr, "CFuncPlatRot", "m_end");
}
void GCFuncPlatRot::SetEnd(QAngle value) {
    SetSchemaValue(m_ptr, "CFuncPlatRot", "m_end", false, value);
}
QAngle GCFuncPlatRot::GetStart() const {
    return GetSchemaValue<QAngle>(m_ptr, "CFuncPlatRot", "m_start");
}
void GCFuncPlatRot::SetStart(QAngle value) {
    SetSchemaValue(m_ptr, "CFuncPlatRot", "m_start", false, value);
}
std::string GCFuncPlatRot::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncPlatRot::IsValid() {
    return (m_ptr != nullptr);
}
GCFuncPlat GCFuncPlatRot::GetParent() const {
    GCFuncPlat value(m_ptr);
    return value;
}
void GCFuncPlatRot::SetParent(GCFuncPlat value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncPlatRot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncPlatRot>("CFuncPlatRot")
        .addConstructor<void (*)(std::string)>()
        .addProperty("End", &GCFuncPlatRot::GetEnd, &GCFuncPlatRot::SetEnd)
        .addProperty("Start", &GCFuncPlatRot::GetStart, &GCFuncPlatRot::SetStart)
        .addProperty("Parent", &GCFuncPlatRot::GetParent, &GCFuncPlatRot::SetParent)
        .addFunction("ToPtr", &GCFuncPlatRot::ToPtr)
        .addFunction("IsValid", &GCFuncPlatRot::IsValid)
        .endClass();
}