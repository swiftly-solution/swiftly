#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncWall::GCFuncWall(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncWall::GCFuncWall(void *ptr) {
    m_ptr = ptr;
}
int32_t GCFuncWall::GetState() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFuncWall", "m_nState");
}
void GCFuncWall::SetState(int32_t value) {
    SetSchemaValue(m_ptr, "CFuncWall", "m_nState", false, value);
}
std::string GCFuncWall::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncWall::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncWall::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncWall::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncWall(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncWall>("CFuncWall")
        .addConstructor<void (*)(std::string)>()
        .addProperty("State", &GCFuncWall::GetState, &GCFuncWall::SetState)
        .addProperty("Parent", &GCFuncWall::GetParent, &GCFuncWall::SetParent)
        .addFunction("ToPtr", &GCFuncWall::ToPtr)
        .addFunction("IsValid", &GCFuncWall::IsValid)
        .endClass();
}