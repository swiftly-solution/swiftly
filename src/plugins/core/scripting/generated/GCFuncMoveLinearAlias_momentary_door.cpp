#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncMoveLinearAlias_momentary_door::GCFuncMoveLinearAlias_momentary_door(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncMoveLinearAlias_momentary_door::GCFuncMoveLinearAlias_momentary_door(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncMoveLinearAlias_momentary_door::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncMoveLinearAlias_momentary_door::IsValid() {
    return (m_ptr != nullptr);
}
GCFuncMoveLinear GCFuncMoveLinearAlias_momentary_door::GetParent() const {
    GCFuncMoveLinear value(m_ptr);
    return value;
}
void GCFuncMoveLinearAlias_momentary_door::SetParent(GCFuncMoveLinear value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncMoveLinearAlias_momentary_door(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncMoveLinearAlias_momentary_door>("CFuncMoveLinearAlias_momentary_door")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCFuncMoveLinearAlias_momentary_door::GetParent, &GCFuncMoveLinearAlias_momentary_door::SetParent)
        .addFunction("ToPtr", &GCFuncMoveLinearAlias_momentary_door::ToPtr)
        .addFunction("IsValid", &GCFuncMoveLinearAlias_momentary_door::IsValid)
        .endClass();
}