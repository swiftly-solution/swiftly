#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicProximity::GCLogicProximity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicProximity::GCLogicProximity(void *ptr) {
    m_ptr = ptr;
}
std::string GCLogicProximity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicProximity::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCLogicProximity::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCLogicProximity::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicProximity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicProximity>("CLogicProximity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCLogicProximity::GetParent, &GCLogicProximity::SetParent)
        .addFunction("ToPtr", &GCLogicProximity::ToPtr)
        .addFunction("IsValid", &GCLogicProximity::IsValid)
        .endClass();
}