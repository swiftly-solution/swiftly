#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBuoyancyHelper::GCBuoyancyHelper(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBuoyancyHelper::GCBuoyancyHelper(void *ptr) {
    m_ptr = ptr;
}
float GCBuoyancyHelper::GetFluidDensity() const {
    return GetSchemaValue<float>(m_ptr, "CBuoyancyHelper", "m_flFluidDensity");
}
void GCBuoyancyHelper::SetFluidDensity(float value) {
    SetSchemaValue(m_ptr, "CBuoyancyHelper", "m_flFluidDensity", false, value);
}
std::string GCBuoyancyHelper::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBuoyancyHelper::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCBuoyancyHelper(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBuoyancyHelper>("CBuoyancyHelper")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FluidDensity", &GCBuoyancyHelper::GetFluidDensity, &GCBuoyancyHelper::SetFluidDensity)
        .addFunction("ToPtr", &GCBuoyancyHelper::ToPtr)
        .addFunction("IsValid", &GCBuoyancyHelper::IsValid)
        .endClass();
}