#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStateMachineComponentUpdater::GCStateMachineComponentUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStateMachineComponentUpdater::GCStateMachineComponentUpdater(void *ptr) {
    m_ptr = ptr;
}
GCAnimStateMachineUpdater GCStateMachineComponentUpdater::GetStateMachine() const {
    GCAnimStateMachineUpdater value(GetSchemaPtr(m_ptr, "CStateMachineComponentUpdater", "m_stateMachine"));
    return value;
}
void GCStateMachineComponentUpdater::SetStateMachine(GCAnimStateMachineUpdater value) {
    SetSchemaValue(m_ptr, "CStateMachineComponentUpdater", "m_stateMachine", false, value);
}
std::string GCStateMachineComponentUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStateMachineComponentUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimComponentUpdater GCStateMachineComponentUpdater::GetParent() const {
    GCAnimComponentUpdater value(m_ptr);
    return value;
}
void GCStateMachineComponentUpdater::SetParent(GCAnimComponentUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCStateMachineComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStateMachineComponentUpdater>("CStateMachineComponentUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StateMachine", &GCStateMachineComponentUpdater::GetStateMachine, &GCStateMachineComponentUpdater::SetStateMachine)
        .addProperty("Parent", &GCStateMachineComponentUpdater::GetParent, &GCStateMachineComponentUpdater::SetParent)
        .addFunction("ToPtr", &GCStateMachineComponentUpdater::ToPtr)
        .addFunction("IsValid", &GCStateMachineComponentUpdater::IsValid)
        .endClass();
}