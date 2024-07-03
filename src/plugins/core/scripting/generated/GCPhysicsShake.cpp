#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysicsShake::GCPhysicsShake(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysicsShake::GCPhysicsShake(void *ptr) {
    m_ptr = ptr;
}
Vector GCPhysicsShake::GetForce() const {
    return GetSchemaValue<Vector>(m_ptr, "CPhysicsShake", "m_force");
}
void GCPhysicsShake::SetForce(Vector value) {
    SetSchemaValue(m_ptr, "CPhysicsShake", "m_force", false, value);
}
std::string GCPhysicsShake::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysicsShake::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCPhysicsShake(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsShake>("CPhysicsShake")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Force", &GCPhysicsShake::GetForce, &GCPhysicsShake::SetForce)
        .addFunction("ToPtr", &GCPhysicsShake::ToPtr)
        .addFunction("IsValid", &GCPhysicsShake::IsValid)
        .endClass();
}