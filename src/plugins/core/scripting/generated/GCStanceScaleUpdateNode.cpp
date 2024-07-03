#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStanceScaleUpdateNode::GCStanceScaleUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStanceScaleUpdateNode::GCStanceScaleUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCAnimParamHandle GCStanceScaleUpdateNode::GetParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CStanceScaleUpdateNode", "m_hParam"));
    return value;
}
void GCStanceScaleUpdateNode::SetParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CStanceScaleUpdateNode", "m_hParam", false, value);
}
std::string GCStanceScaleUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStanceScaleUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCStanceScaleUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCStanceScaleUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCStanceScaleUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStanceScaleUpdateNode>("CStanceScaleUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Param", &GCStanceScaleUpdateNode::GetParam, &GCStanceScaleUpdateNode::SetParam)
        .addProperty("Parent", &GCStanceScaleUpdateNode::GetParent, &GCStanceScaleUpdateNode::SetParent)
        .addFunction("ToPtr", &GCStanceScaleUpdateNode::ToPtr)
        .addFunction("IsValid", &GCStanceScaleUpdateNode::IsValid)
        .endClass();
}