#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncVehicleClip::GCFuncVehicleClip(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncVehicleClip::GCFuncVehicleClip(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncVehicleClip::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncVehicleClip::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncVehicleClip::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncVehicleClip::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncVehicleClip(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncVehicleClip>("CFuncVehicleClip")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCFuncVehicleClip::GetParent, &GCFuncVehicleClip::SetParent)
        .addFunction("ToPtr", &GCFuncVehicleClip::ToPtr)
        .addFunction("IsValid", &GCFuncVehicleClip::IsValid)
        .endClass();
}