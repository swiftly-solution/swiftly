#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSpeedScaleUpdateNode::GCSpeedScaleUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSpeedScaleUpdateNode::GCSpeedScaleUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCAnimParamHandle GCSpeedScaleUpdateNode::GetParamIndex() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CSpeedScaleUpdateNode", "m_paramIndex"));
    return value;
}
void GCSpeedScaleUpdateNode::SetParamIndex(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CSpeedScaleUpdateNode", "m_paramIndex", false, value);
}
std::string GCSpeedScaleUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSpeedScaleUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCSpeedScaleUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCSpeedScaleUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSpeedScaleUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSpeedScaleUpdateNode>("CSpeedScaleUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ParamIndex", &GCSpeedScaleUpdateNode::GetParamIndex, &GCSpeedScaleUpdateNode::SetParamIndex)
        .addProperty("Parent", &GCSpeedScaleUpdateNode::GetParent, &GCSpeedScaleUpdateNode::SetParent)
        .addFunction("ToPtr", &GCSpeedScaleUpdateNode::ToPtr)
        .addFunction("IsValid", &GCSpeedScaleUpdateNode::IsValid)
        .endClass();
}