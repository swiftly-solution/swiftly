#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCItemKevlar::GCItemKevlar(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCItemKevlar::GCItemKevlar(void *ptr) {
    m_ptr = ptr;
}
std::string GCItemKevlar::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCItemKevlar::IsValid() {
    return (m_ptr != nullptr);
}
GCItem GCItemKevlar::GetParent() const {
    GCItem value(m_ptr);
    return value;
}
void GCItemKevlar::SetParent(GCItem value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCItemKevlar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemKevlar>("CItemKevlar")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCItemKevlar::GetParent, &GCItemKevlar::SetParent)
        .addFunction("ToPtr", &GCItemKevlar::ToPtr)
        .addFunction("IsValid", &GCItemKevlar::IsValid)
        .endClass();
}