#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCollisionGroupContext_t::GCollisionGroupContext_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCollisionGroupContext_t::GCollisionGroupContext_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GCollisionGroupContext_t::GetCollisionGroupNumber() const {
    return GetSchemaValue<int32_t>(m_ptr, "CollisionGroupContext_t", "m_nCollisionGroupNumber");
}
void GCollisionGroupContext_t::SetCollisionGroupNumber(int32_t value) {
    SetSchemaValue(m_ptr, "CollisionGroupContext_t", "m_nCollisionGroupNumber", true, value);
}
std::string GCollisionGroupContext_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCollisionGroupContext_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCollisionGroupContext_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCollisionGroupContext_t>("CollisionGroupContext_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CollisionGroupNumber", &GCollisionGroupContext_t::GetCollisionGroupNumber, &GCollisionGroupContext_t::SetCollisionGroupNumber)
        .addFunction("ToPtr", &GCollisionGroupContext_t::ToPtr)
        .addFunction("IsValid", &GCollisionGroupContext_t::IsValid)
        .endClass();
}