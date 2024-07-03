#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCZeroPoseUpdateNode::GCZeroPoseUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCZeroPoseUpdateNode::GCZeroPoseUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCZeroPoseUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCZeroPoseUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCLeafUpdateNode GCZeroPoseUpdateNode::GetParent() const {
    GCLeafUpdateNode value(m_ptr);
    return value;
}
void GCZeroPoseUpdateNode::SetParent(GCLeafUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCZeroPoseUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCZeroPoseUpdateNode>("CZeroPoseUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCZeroPoseUpdateNode::GetParent, &GCZeroPoseUpdateNode::SetParent)
        .addFunction("ToPtr", &GCZeroPoseUpdateNode::ToPtr)
        .addFunction("IsValid", &GCZeroPoseUpdateNode::IsValid)
        .endClass();
}