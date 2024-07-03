#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCycleControlUpdateNode::GCCycleControlUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCycleControlUpdateNode::GCCycleControlUpdateNode(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCCycleControlUpdateNode::GetValueSource() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCycleControlUpdateNode", "m_valueSource");
}
void GCCycleControlUpdateNode::SetValueSource(uint64_t value) {
    SetSchemaValue(m_ptr, "CCycleControlUpdateNode", "m_valueSource", false, value);
}
GCAnimParamHandle GCCycleControlUpdateNode::GetParamIndex() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CCycleControlUpdateNode", "m_paramIndex"));
    return value;
}
void GCCycleControlUpdateNode::SetParamIndex(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CCycleControlUpdateNode", "m_paramIndex", false, value);
}
std::string GCCycleControlUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCycleControlUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCCycleControlUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCCycleControlUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCycleControlUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCycleControlUpdateNode>("CCycleControlUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ValueSource", &GCCycleControlUpdateNode::GetValueSource, &GCCycleControlUpdateNode::SetValueSource)
        .addProperty("ParamIndex", &GCCycleControlUpdateNode::GetParamIndex, &GCCycleControlUpdateNode::SetParamIndex)
        .addProperty("Parent", &GCCycleControlUpdateNode::GetParent, &GCCycleControlUpdateNode::SetParent)
        .addFunction("ToPtr", &GCCycleControlUpdateNode::ToPtr)
        .addFunction("IsValid", &GCCycleControlUpdateNode::IsValid)
        .endClass();
}