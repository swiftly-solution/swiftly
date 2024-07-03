#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFireCrackerBlast::GCFireCrackerBlast(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFireCrackerBlast::GCFireCrackerBlast(void *ptr) {
    m_ptr = ptr;
}
std::string GCFireCrackerBlast::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFireCrackerBlast::IsValid() {
    return (m_ptr != nullptr);
}
GCInferno GCFireCrackerBlast::GetParent() const {
    GCInferno value(m_ptr);
    return value;
}
void GCFireCrackerBlast::SetParent(GCInferno value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFireCrackerBlast(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFireCrackerBlast>("CFireCrackerBlast")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCFireCrackerBlast::GetParent, &GCFireCrackerBlast::SetParent)
        .addFunction("ToPtr", &GCFireCrackerBlast::ToPtr)
        .addFunction("IsValid", &GCFireCrackerBlast::IsValid)
        .endClass();
}