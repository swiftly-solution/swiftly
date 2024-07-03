#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBtNodeDecorator::GCBtNodeDecorator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBtNodeDecorator::GCBtNodeDecorator(void *ptr) {
    m_ptr = ptr;
}
std::string GCBtNodeDecorator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBtNodeDecorator::IsValid() {
    return (m_ptr != nullptr);
}
GCBtNode GCBtNodeDecorator::GetParent() const {
    GCBtNode value(m_ptr);
    return value;
}
void GCBtNodeDecorator::SetParent(GCBtNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBtNodeDecorator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtNodeDecorator>("CBtNodeDecorator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCBtNodeDecorator::GetParent, &GCBtNodeDecorator::SetParent)
        .addFunction("ToPtr", &GCBtNodeDecorator::ToPtr)
        .addFunction("IsValid", &GCBtNodeDecorator::IsValid)
        .endClass();
}