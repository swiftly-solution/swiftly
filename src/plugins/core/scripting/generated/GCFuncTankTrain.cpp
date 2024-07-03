#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncTankTrain::GCFuncTankTrain(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncTankTrain::GCFuncTankTrain(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCFuncTankTrain::GetOnDeath() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFuncTankTrain", "m_OnDeath"));
    return value;
}
void GCFuncTankTrain::SetOnDeath(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFuncTankTrain", "m_OnDeath", false, value);
}
std::string GCFuncTankTrain::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncTankTrain::IsValid() {
    return (m_ptr != nullptr);
}
GCFuncTrackTrain GCFuncTankTrain::GetParent() const {
    GCFuncTrackTrain value(m_ptr);
    return value;
}
void GCFuncTankTrain::SetParent(GCFuncTrackTrain value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncTankTrain(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTankTrain>("CFuncTankTrain")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnDeath", &GCFuncTankTrain::GetOnDeath, &GCFuncTankTrain::SetOnDeath)
        .addProperty("Parent", &GCFuncTankTrain::GetParent, &GCFuncTankTrain::SetParent)
        .addFunction("ToPtr", &GCFuncTankTrain::ToPtr)
        .addFunction("IsValid", &GCFuncTankTrain::IsValid)
        .endClass();
}