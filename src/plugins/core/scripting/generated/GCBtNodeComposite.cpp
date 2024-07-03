#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBtNodeComposite::GCBtNodeComposite(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBtNodeComposite::GCBtNodeComposite(void *ptr) {
    m_ptr = ptr;
}
std::string GCBtNodeComposite::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBtNodeComposite::IsValid() {
    return (m_ptr != nullptr);
}
GCBtNode GCBtNodeComposite::GetParent() const {
    GCBtNode value(m_ptr);
    return value;
}
void GCBtNodeComposite::SetParent(GCBtNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBtNodeComposite(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtNodeComposite>("CBtNodeComposite")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCBtNodeComposite::GetParent, &GCBtNodeComposite::SetParent)
        .addFunction("ToPtr", &GCBtNodeComposite::ToPtr)
        .addFunction("IsValid", &GCBtNodeComposite::IsValid)
        .endClass();
}