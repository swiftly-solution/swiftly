#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFollowTargetUpdateNode::GCFollowTargetUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFollowTargetUpdateNode::GCFollowTargetUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GFollowTargetOpFixedSettings_t GCFollowTargetUpdateNode::GetOpFixedData() const {
    GFollowTargetOpFixedSettings_t value(GetSchemaPtr(m_ptr, "CFollowTargetUpdateNode", "m_opFixedData"));
    return value;
}
void GCFollowTargetUpdateNode::SetOpFixedData(GFollowTargetOpFixedSettings_t value) {
    SetSchemaValue(m_ptr, "CFollowTargetUpdateNode", "m_opFixedData", false, value);
}
GCAnimParamHandle GCFollowTargetUpdateNode::GetParameterPosition() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CFollowTargetUpdateNode", "m_hParameterPosition"));
    return value;
}
void GCFollowTargetUpdateNode::SetParameterPosition(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CFollowTargetUpdateNode", "m_hParameterPosition", false, value);
}
GCAnimParamHandle GCFollowTargetUpdateNode::GetParameterOrientation() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CFollowTargetUpdateNode", "m_hParameterOrientation"));
    return value;
}
void GCFollowTargetUpdateNode::SetParameterOrientation(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CFollowTargetUpdateNode", "m_hParameterOrientation", false, value);
}
std::string GCFollowTargetUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFollowTargetUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCFollowTargetUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCFollowTargetUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFollowTargetUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFollowTargetUpdateNode>("CFollowTargetUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OpFixedData", &GCFollowTargetUpdateNode::GetOpFixedData, &GCFollowTargetUpdateNode::SetOpFixedData)
        .addProperty("ParameterPosition", &GCFollowTargetUpdateNode::GetParameterPosition, &GCFollowTargetUpdateNode::SetParameterPosition)
        .addProperty("ParameterOrientation", &GCFollowTargetUpdateNode::GetParameterOrientation, &GCFollowTargetUpdateNode::SetParameterOrientation)
        .addProperty("Parent", &GCFollowTargetUpdateNode::GetParent, &GCFollowTargetUpdateNode::SetParent)
        .addFunction("ToPtr", &GCFollowTargetUpdateNode::ToPtr)
        .addFunction("IsValid", &GCFollowTargetUpdateNode::IsValid)
        .endClass();
}