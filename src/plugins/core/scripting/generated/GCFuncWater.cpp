#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncWater::GCFuncWater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncWater::GCFuncWater(void *ptr) {
    m_ptr = ptr;
}
GCBuoyancyHelper GCFuncWater::GetBuoyancyHelper() const {
    GCBuoyancyHelper value(GetSchemaPtr(m_ptr, "CFuncWater", "m_BuoyancyHelper"));
    return value;
}
void GCFuncWater::SetBuoyancyHelper(GCBuoyancyHelper value) {
    SetSchemaValue(m_ptr, "CFuncWater", "m_BuoyancyHelper", false, value);
}
std::string GCFuncWater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncWater::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncWater::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncWater::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncWater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncWater>("CFuncWater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BuoyancyHelper", &GCFuncWater::GetBuoyancyHelper, &GCFuncWater::SetBuoyancyHelper)
        .addProperty("Parent", &GCFuncWater::GetParent, &GCFuncWater::SetParent)
        .addFunction("ToPtr", &GCFuncWater::ToPtr)
        .addFunction("IsValid", &GCFuncWater::IsValid)
        .endClass();
}