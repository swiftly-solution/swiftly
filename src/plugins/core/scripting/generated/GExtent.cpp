#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GExtent::GExtent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GExtent::GExtent(void *ptr) {
    m_ptr = ptr;
}
Vector GExtent::GetLo() const {
    return GetSchemaValue<Vector>(m_ptr, "Extent", "lo");
}
void GExtent::SetLo(Vector value) {
    SetSchemaValue(m_ptr, "Extent", "lo", false, value);
}
Vector GExtent::GetHi() const {
    return GetSchemaValue<Vector>(m_ptr, "Extent", "hi");
}
void GExtent::SetHi(Vector value) {
    SetSchemaValue(m_ptr, "Extent", "hi", false, value);
}
std::string GExtent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GExtent::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassExtent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GExtent>("Extent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Lo", &GExtent::GetLo, &GExtent::SetLo)
        .addProperty("Hi", &GExtent::GetHi, &GExtent::SetHi)
        .addFunction("ToPtr", &GExtent::ToPtr)
        .addFunction("IsValid", &GExtent::IsValid)
        .endClass();
}