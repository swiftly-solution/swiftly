#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSymbolAnimParameter::GCSymbolAnimParameter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSymbolAnimParameter::GCSymbolAnimParameter(void *ptr) {
    m_ptr = ptr;
}
std::string GCSymbolAnimParameter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSymbolAnimParameter::IsValid() {
    return (m_ptr != nullptr);
}
GCConcreteAnimParameter GCSymbolAnimParameter::GetParent() const {
    GCConcreteAnimParameter value(m_ptr);
    return value;
}
void GCSymbolAnimParameter::SetParent(GCConcreteAnimParameter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSymbolAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSymbolAnimParameter>("CSymbolAnimParameter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSymbolAnimParameter::GetParent, &GCSymbolAnimParameter::SetParent)
        .addFunction("ToPtr", &GCSymbolAnimParameter::ToPtr)
        .addFunction("IsValid", &GCSymbolAnimParameter::IsValid)
        .endClass();
}