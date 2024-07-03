#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicScript::GCLogicScript(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicScript::GCLogicScript(void *ptr) {
    m_ptr = ptr;
}
std::string GCLogicScript::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicScript::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCLogicScript::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCLogicScript::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicScript(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicScript>("CLogicScript")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCLogicScript::GetParent, &GCLogicScript::SetParent)
        .addFunction("ToPtr", &GCLogicScript::ToPtr)
        .addFunction("IsValid", &GCLogicScript::IsValid)
        .endClass();
}